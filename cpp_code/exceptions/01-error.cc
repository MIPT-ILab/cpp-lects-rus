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
  if (n == 0) return 1 / n;
  foo (n - 1);
}

int 
main ()
{
  foo (5);
}

