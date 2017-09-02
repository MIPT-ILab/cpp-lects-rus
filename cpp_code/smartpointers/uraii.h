#ifndef URAII_GUARD_
#define URAII_GUARD_

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

template <typename T> 
class URAIIPtr {
  T *ptr_;
public:
  URAIIPtr(T *ptr = nullptr) : ptr_(ptr) {}
  ~URAIIPtr() { delete ptr_; }
  URAIIPtr(const URAIIPtr&) = delete;
  URAIIPtr& operator= (const URAIIPtr&) = delete;
  URAIIPtr(URAIIPtr&& rhs) : ptr_(rhs.ptr_) { rhs.ptr_ = nullptr; } 
  URAIIPtr& operator= (URAIIPtr&& rhs) { swap(*this, rhs); return *this; }

  T operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; };
  T* get() const { return ptr_; }
};

#endif