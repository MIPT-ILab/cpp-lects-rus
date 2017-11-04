#include <assert.h>

int foo(int* a, int len) {
  assert ((a != 0) && (len > 1));
  return a[len/2]; /* ORLY? */
}

int
main ()
{
  int a[10];
  int t = foo (a, 100);
  return t;
}

