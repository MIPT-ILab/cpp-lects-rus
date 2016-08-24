#include <assert.h>

extern unsigned lookup[];

unsigned __attribute__ ((noinline))
fact (unsigned x)
{
  assert (x < 13);
  return lookup[x];
}

int
main (void)
{
  assert (fact (10) == 3628800);
  return 0;
}

