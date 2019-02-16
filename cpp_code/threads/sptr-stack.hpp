#pragma once

#include <atomic>
#include <memory>

using std::atomic_compare_exchange_strong;
using std::atomic_load;
using std::make_shared;
using std::move;
using std::shared_ptr;

template <typename T>
class slist_t {
  struct Node {
    shared_ptr<Node> next;
    T t;
  };
  shared_ptr<Node> head {nullptr};

public:
  class reference {
    shared_ptr<Node> p_;
  public:
    reference(shared_ptr<Node> p) : p_(p) {}
    T& operator*() { return p_->t; }
    T* operator->() { return &p_->t; }
  };

  slist_t() = default;
  T* find(T t) const;
  void push_front(T t);
  void pop_front();
  
  // ~slist_t() = default;
};

template <typename T>
T* slist_t<T>::find(T t) const {
  auto first = atomic_load(&head);
  while (first && first->t != t)
    first = first->next;
  return reference(move(first));
}

template <typename T>
void slist_t<T>::push_front(T t) {
  auto p = make_shared<Node>(Node{head, move(t)});
  while(!atomic_compare_exchange_strong(&head, &p->next, p)) {}
}

template <typename T>
void slist_t<T>::pop_front() {
  auto p = atomic_load(&head);
  while(p && !atomic_compare_exchange_strong(&head, &p, p->next)) {}
}

