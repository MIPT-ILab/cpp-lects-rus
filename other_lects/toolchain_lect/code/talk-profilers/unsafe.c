#include <stdio.h>
#include <stdlib.h>

int
foo (int x) {
  int i;
  int * buf = malloc (x * sizeof(int));

  if (x < 2) return 1;

  buf[0] = 1;
  buf[1] = 1;
  for (i = 2; i < x; ++i)
    buf[i] = buf[i - 1] + buf[i - 2];

  int result = buf[x - 1];
  free (buf);

  return result;
}

int
main (void)
{
  printf ("%d\n", foo(15));
  return 0;
}

