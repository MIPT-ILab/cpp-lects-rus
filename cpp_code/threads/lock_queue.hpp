#pragma once

#include <atomic>
#include <utility>

using std::atomic;
using std::move;

template <typename T>
struct lock_queue {
private:
  struct Node {
    Node (T val) : value(move(val)), next(nullptr) { }
    T value;
    atomic<Node*> next; // ???
  };
  
  Node *first, *last;
  atomic<Node*> divider; // ???
  atomic<bool> producerLock;
  atomic<bool> consumerLock;
  
public:
  lock_queue() {
    first = divider = last = new Node(T{});
    producerLock = consumerLock = false;
  }
  
  ~lock_queue() {
    while (first != nullptr) {
      Node* tmp = first;
      first = tmp->next;
      delete tmp;
    }
  }

  // returns false if queue is empty
  bool pop(T& result) {
    bool retval = false;
    
    while(consumerLock.exchange(true)) {} // lock

    // --- CRITICAL SECTION
    auto divl = divider.load();
    if (divl->next != nullptr) {
      auto nxt = divl->next.load();
      result = move(nxt->value);
      divider.store(nxt);
      retval = true;
    }
    // ---

    consumerLock = false; // unlock
    return retval;
  }

  void push(T t) {
    Node* tmp = new Node(move(t));

    while (producerLock.exchange(true)) {}	// lock

    // --- CRITICAL SECTION
    last->next = tmp;
    last = last->next;

    while (first != divider) {
      Node* tmp = first;
      first = first->next;
      delete tmp;
    }
    // ---

    producerLock = false; // unlock
  }
};
