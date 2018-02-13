#include <iostream>

using std::cout;

struct UnwShow
{
  UnwShow () { cout << "ctor\n"; }
  ~UnwShow () { cout << "dtor\n"; } 
};

int foo (int n) 
{
  UnwShow s;
  if (n == 0) throw 1;
  foo (n - 1);
}

int 
main ()
{
try {
  foo (5);
}
catch (...) {}
}

