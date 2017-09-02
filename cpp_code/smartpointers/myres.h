#ifndef MYRES_GUARD_
#define MYRES_GUARD_

#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

struct MyRes {
  int valid_;

  MyRes() : valid_(1) { 
    cout << "MyRes ctor ()" << endl; 
  }

  MyRes(int, double) : valid_(1) { 
    cout << "MyRes ctor (int, double)" << endl; 
  }

  MyRes(const MyRes& rhs) : valid_(rhs.valid_) { 
    cout << "MyRes copy ctor" << endl; 
    if (valid_ == 0)
      cout << "Copying expired object!" << endl; 
  }

  MyRes(MyRes&& rhs) : valid_(rhs.valid_) {    
    cout << "MyRes move ctor" << endl; 
    if (valid_ == 0)
      cout << "Moving from expired object!" << endl; 
    rhs.valid_ = 0;
  }

  MyRes& operator=(const MyRes& rhs) { 
    cout << "MyRes copy assign" << endl; 
    valid_ = rhs.valid_;
    return *this; 
  }

  MyRes& operator=(MyRes&& rhs) { 
    cout << "MyRes move assign" << endl;
    if (&rhs != this) {
      valid_ = rhs.valid_;
      rhs.valid_ = 0;
    } 
    return *this; 
  }

  ~MyRes() { 
    cout << "MyRes dtor" << endl;
    if (valid_ == 0)
      cout << "Destructing expired object (may be double deletion)" << endl;
    valid_ = 0;
  }

  void use() { 
    cout << "MyRes used" << endl; 
    if (valid_ == 0)
      cout << "Using expired object" << endl;
  }
};

#endif