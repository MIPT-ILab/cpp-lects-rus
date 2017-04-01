#include <cstdio>

using namespace std;

struct UnwShow
{
  UnwShow () { printf ("ctor\n"); }
  ~UnwShow () { printf ("dtor\n"); }
};

void __attribute__ ((noinline))
foo (int n)
{
  UnwShow s;
  if (n == 0) throw 1;
  foo (n - 1);
}

int
main (void)
{
  try 
  {
    foo (3);
  }
  catch (...)
  {
  }
  return 0;
}

