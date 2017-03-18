#include <iostream>

using namespace std;

struct S {
  int foo () & { cout << "lval" << endl; }
  int foo () && { cout << "rval" << endl; }
};

S x {};
S bar () { return x; }

int main (void) {
  x.foo();
  bar().foo();
}

