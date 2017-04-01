#include <iostream>

using std::cout;
using std::endl;

template <typename T> void f(T&&) { cout << 1 << endl; } 
template<> void f<>(double&&) { cout << 2 << endl; }
void f(int&) { cout << 3 << endl; }
template <typename T> void f(T*) { cout << 4 << endl; }
template<> void f<>(int*) { cout << 5 << endl; }

int
main ()
{
  int x = 1;
  double y = 1.0;

  f(x);
  f(y);
  f<>(1);
  f(1.0);
}

