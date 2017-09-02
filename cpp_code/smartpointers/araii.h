#ifndef ARAII_GUARD_
#define ARAII_GUARD_

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

template <typename T> class ARAIIPtr {
  T *ptr_;
public:
  ARAIIPtr(T *ptr = nullptr) : ptr_(ptr) {}
  ~ARAIIPtr() { delete ptr_; }
  ARAIIPtr(ARAIIPtr& rhs) : ptr_(rhs.ptr_) { 
    rhs.ptr_ = nullptr; 
  }
  ARAIIPtr& operator= (ARAIIPtr rhs) { 
    swap(*this, rhs); return *this; 
  }
  T operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; }
};

#endif