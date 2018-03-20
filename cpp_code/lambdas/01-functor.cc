#include <iostream>

using std::cout;
using std::endl;

struct Foo {
  using fptr_t = int (*) (int, int);

  static int foo(int n1, int n2) {
    return n1 + n2;
  }

#ifdef BRACES
  int operator() (int n1, int n2) {
    cout << "operator()" << endl;
    return foo(n1, n2);
  }
#endif
  
  operator fptr_t() const {
    cout << "implicit cast" << endl;
    return foo;
  }
};

int main()
{
  Foo foo;
  int n = foo(5, 6);
  cout << n << endl;
}

