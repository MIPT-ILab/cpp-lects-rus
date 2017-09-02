#ifndef SRAII_GUARD_
#define SRAII_GUARD_

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

template <typename T> 
class SRAIIPtr {
  T *ptr_;
public:
  SRAIIPtr(T *ptr = nullptr) : ptr_(ptr) {}
  ~SRAIIPtr() { delete ptr_; }
  SRAIIPtr(const SRAIIPtr&) = delete;
  SRAIIPtr& operator= (const SRAIIPtr&) = delete;
  T operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; };
  T* get() const { return ptr_; }
};

#endif