#include <assert.h>

int __attribute__ ((noinline))
foo(int* a, int len) {
  assert ((a != 0) && (len > 1));
  return a[len/2];    /* ORLY? */
}

int main (void)
{
  int a[5] = {1, 2, 3, 4, 5};
  int x = foo (a, 12); // oops
  return x;
}


