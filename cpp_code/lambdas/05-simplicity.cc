#include <iostream>

using std::cout;
using std::endl;

struct Parent1 {
  void foo (int) { cout << "forint" << endl; }
};

struct Parent2 {
  void foo (double) { cout << "fordbl" << endl; }  
};

struct Child : public Parent1, public Parent2 {
#ifdef USE1
  using Parent1::foo;
#endif
#ifdef USE2
  using Parent2::foo;
#endif
};

int
main () {
  Child c;
  c.foo(3);
  c.foo(3.0);
}
