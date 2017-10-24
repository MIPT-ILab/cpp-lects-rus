#include <iostream>
#include <boost/intrusive_ptr.hpp>

using std::cout;
using std::endl;

template<typename T>
void intrusive_ptr_add_ref(T* ptr)
{
  cout << "AddRef" << endl;
  ptr->add_ref();
}

template<typename T>
void intrusive_ptr_release(T* ptr)
{
  cout << "Release" << endl;
  if(!ptr->release())
    delete ptr;
}

class test
{
  int ref_cnt_;

public:
   test() : ref_cnt_(0) { cout << "test ctor" << endl; } 
   ~test() { cout << "test dtor" << endl; }
   test(const test&) = delete;
   test& operator= (const test&) = delete;
   int add_ref() { return ++ref_cnt_; }
   int release() { return --ref_cnt_; }
};

int main()
{
  test* p = 0;
  cout << "--- start 1 ---" << endl;
  boost::intrusive_ptr<test> ptr;
   
  {
    cout << "--- start 2 ---" << endl;
    p = new test();
    boost::intrusive_ptr<test> ptr2(p);
    ptr = ptr2;
    cout << "--- finish 2 ---" << endl;
  }

  cout << "--- finish 1 ---" << endl;
  return 0;
}

