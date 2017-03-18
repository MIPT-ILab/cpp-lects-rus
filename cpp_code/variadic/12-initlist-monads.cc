#include <iostream>

using std::cout;
using std::endl;

int foo1() { cout << 1 << endl; return 0; }
int foo2() { cout << 2 << endl; return 0; }
int foo3() { cout << 3 << endl; return 0; }

void foo (int, int, int) {}

void foo (std::initializer_list<int>) {}

int
main ()
{
  foo(foo1(), foo2(), foo3());
  foo({foo1(), foo2(), foo3()});
}

