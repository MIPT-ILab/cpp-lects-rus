#ifndef MYRES_GUARD_
#define MYRES_GUARD_

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

struct MyRes {
  int valid_;
  int index_;

  MyRes(int i = 0) : valid_(1), index_(i) { 
    cout << "MyRes " << index_ << " ctor ()" << endl; 
  }

  MyRes(int i, double) : valid_(1), index_(i) { 
    cout << "MyRes " << index_ << " ctor (int, double)" << endl; 
  }

  MyRes(const MyRes& rhs) : valid_(rhs.valid_), index_(rhs.index_) { 
    cout << "MyRes " << index_ << " copy ctor" << endl; 
    if (valid_ == 0)
      cout << "Copying expired object!" << endl; 
  }

  MyRes(MyRes&& rhs) : valid_(rhs.valid_), index_(rhs.index_) {    
    cout << "MyRes " << index_ << " move ctor" << endl; 
    if (valid_ == 0)
      cout << "Moving from expired object!" << endl; 
    rhs.valid_ = 0;
  }

  MyRes& operator=(const MyRes& rhs) { 
    cout << "MyRes " << index_ << " copy assign" << endl; 
    valid_ = rhs.valid_;
    index_ = rhs.index_;
    return *this; 
  }

  MyRes& operator=(MyRes&& rhs) { 
    cout << "MyRes " << index_ << " move assign" << endl;
    if (&rhs != this) {
      valid_ = rhs.valid_;
      index_ = rhs.index_;
      rhs.valid_ = 0;
    } 
    return *this; 
  }

  ~MyRes() { 
    cout << "MyRes " << index_ << " dtor" << endl;
    if (valid_ == 0)
      cout << "Destructing expired object (may be double deletion)" << endl;
    valid_ = 0;
  }

  void use() { 
    cout << "MyRes " << index_ << " used" << endl; 
    if (valid_ == 0)
      cout << "Using expired object" << endl;
  }
};

#endif
