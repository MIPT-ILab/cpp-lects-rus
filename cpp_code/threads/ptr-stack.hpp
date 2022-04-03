#pragma once

#include <atomic>

using std::atomic;

template <typename T>
class slist_t {
  struct Node {
    Node *next;
    T t;
  };
  atomic<Node *> head {nullptr};

public:
  slist_t() = default;
  T* find(T t) const;
  void push_front(T t);
  void pop_front();
  
  ~slist_t();
};

template <typename T>
slist_t<T>::~slist_t() {
  auto first = head.load();
  while (first) {
    auto unlinked = first;
    first = first->next;
    delete unlinked;
  }
}

template <typename T>
T* slist_t<T>::find(T t) const {
  auto first = head.load();
  while (first && first->t != t)
    first = first->next;
  return first ? &first->t : nullptr;
}

template <typename T>
void slist_t<T>::push_front(T t) {
  auto p = new Node{head, std::move(t)};

  // Bad idea:
  // head = p;

  // Good idea:
  while(!head.compare_exchange_weak(p->next, p)) {}
}

template <typename T>
void slist_t<T>::pop_front() {
  auto p = head.load();
  while(p && !head.compare_exchange_weak(p, p->next)) {}
  delete p;
}

