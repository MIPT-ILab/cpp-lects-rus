#include <iostream>

using std::cout;
using std::endl;

struct B {
  int a = 2;
  virtual void f () {
    cout << "B::f " << a << endl;
  }
};

struct D : B {
  int b = 3;
  void f() override {
    cout << "D::f " << a << " " << b << endl;
  }
};

void use(B b) { b.f(); }

int
main ()
{
  D d;
  use(d);
}

