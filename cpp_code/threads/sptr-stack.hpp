#pragma once

#include <atomic>
#include <memory>

template <typename T>
class slist_t {
  struct Node {
    std::shared_ptr<Node> next {nullptr};
    T data;
    Node(std::shared_ptr<Node> n, T t) : next(n), data(t) {}
    Node(const Node&) = default;
  };
  std::atomic<std::shared_ptr<Node>> head {nullptr};

public:
  class reference {
    std::shared_ptr<Node> p_;
  public:
    reference(std::shared_ptr<Node> p) : p_(p) {}
    T& operator*() { return p_->t; }
    T* operator->() { return &p_->t; }
  };

  slist_t() = default;
  reference find(T t) const;
  void push_front(T t);
  void pop_front();
  ~slist_t() = default;
};

template <typename T>
typename slist_t<T>::reference slist_t<T>::find(T t) const {
  auto first = head.load();
  while (first && first->t != t)
    first = first->next;
  return slist_t<T>::reference(first);
}

template <typename T>
void slist_t<T>::push_front(T t) {
  auto h = head.load();
  auto p = std::make_shared<Node>(h, std::move(t));
  while(!head.compare_exchange_weak(p->next, p)) {}
}

template <typename T>
void slist_t<T>::pop_front() {
  auto p = head.load();
  while(p && !head.compare_exchange_weak(p, p->next)) {}
}

