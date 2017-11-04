#include <cstdio>
#include <iostream>
#include <memory>

using std::cout;
using std::default_delete;
using std::endl;
using std::make_unique;
using std::printf;
using std::unique_ptr;

using std::make_shared;
using std::shared_ptr;

void*
operator new (size_t sz)
{
  void* p = malloc(sz);
  printf("alloc: %llu\n", (unsigned long long)(sz));
  return p;
}

template <typename T> struct MyClassDeleter {
  void operator()(T *t) { delete [] t; }
};

auto MyLambdaDeleter = [](auto *t) { delete [] t; };

template <typename T> 
void MyFuncDeleter(T *t) {
  delete [] t;
}

int
main ()
{
  auto *ui0 = new int[1000];
  delete [] ui0;
  auto ui1 = make_unique<int[]>(1000);
  unique_ptr<int[]> ui2 (new int[1000]());  
  unique_ptr<int, MyClassDeleter<int>> ui3 (new int[1000]());
  unique_ptr<int, decltype(MyLambdaDeleter)> ui4 (new int[1000](), MyLambdaDeleter);
  unique_ptr<int, decltype(&MyFuncDeleter<int>)> ui5 (new int[1000](), MyFuncDeleter<int>);

  cout << "\tui0:" << sizeof(ui0)
       << "\tui1:" << sizeof(ui1)
       << "\tui2:" << sizeof(ui2)
       << "\tui3:" << sizeof(ui3)
       << "\tui4:" << sizeof(ui4)
       << "\tui5:" << sizeof(ui5)
       << endl;

  // what about this way?
  // auto si1 = make_shared<int[]>(1000);

  shared_ptr<int> si2 (new int[1000], default_delete<int[]>());
  shared_ptr<int> si3 (new int[1000], MyClassDeleter<int>());  
  shared_ptr<int> si4 (new int[1000], &MyFuncDeleter<int>);
 
//       << "\tsi1:" << sizeof(si1)
  cout << "\tsi2:" << sizeof(si2)
       << "\tsi3:" << sizeof(si3)
       << "\tsi4:" << sizeof(si4)
       << endl;
}

