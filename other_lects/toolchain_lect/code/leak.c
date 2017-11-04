#include <stdlib.h>

char* __attribute__((noinline))
leak() {
  char *ix = malloc(10);
  return ix;
}

int
main ()
{
  leak();
}

