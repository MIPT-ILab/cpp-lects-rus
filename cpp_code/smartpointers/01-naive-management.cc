#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

struct MyRes {
  MyRes(int, double) {
    cout << "MyRes ctor" << endl;
  }

  void use() { 
    cout << "MyRes used" << endl;
  }

  ~MyRes() {
    cout << "MyRes dtor" << endl;
  }
};

int 
naive (int x, double y) 
{
  MyRes *ptr = new MyRes(x, y);

  ptr->use();

  if (x > 3) 
    {
      delete ptr;
      return -1;
    }

  delete ptr; 
  return 0;
}

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
};

int 
scoped (int x, double y) 
{
  SRAIIPtr<MyRes> ptr(new MyRes(x, y));

  ptr->use();

  if (x > 3) 
    return -1;

  return 0;
}


int
main ()
{
  cout << "--- naive ---" << endl;
  assert(0 == naive (2, 1.0));
  assert(-1 == naive (4, 1.0));
  cout << "--- scoped ---" << endl;
  assert(0 == scoped (2, 1.0));
  assert(-1 == scoped (4, 1.0));
}

