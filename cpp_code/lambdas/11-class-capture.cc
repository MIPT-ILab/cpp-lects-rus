#include <iostream>

using std::cout;
using std::endl;

struct Foo {
  int x_;
  void func () {
    // [x_] () mutable { x_ += 3; } (); // FAIL
    // [&x_] () mutable { x_ += 3; } (); // FAIL
    [=] () mutable { x_ += 3; } (); // OK
    [&] () mutable { x_ += 3; } (); // OK
    [this] () mutable { x_ += 3; } (); // OK
  }
};

int 
main()
{
  Foo x{1};
  x.func();
  cout << x.x_ << endl;
}


