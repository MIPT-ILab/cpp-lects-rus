#include <iostream>

using std::cout;
using std::endl;

template <typename T, typename U> 
struct Foo {
  Foo () { cout << 1 << endl; }
};

template <typename T> 
struct Foo<T, T> {
  Foo () { cout << 2 << endl; }
}; 

template <typename T> 
struct Foo<T, int> {
  Foo () { cout << 3 << endl; }
}; 

template <typename T, typename U> 
struct Foo<T*, U*> {
  Foo () { cout << 4 << endl; }
};

int
main ()
{
  Foo<int, float> mif;   // 1
  Foo<float, float> mff; // 2
  Foo<float, int> mfi;   // 3
  Foo<int*, float*> mp;  // 4
}

