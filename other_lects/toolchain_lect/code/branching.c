#include <stdio.h>

int __attribute__ ((noinline))
foo(int x)
{
  s3:
  if (x > 0) goto s1;
  x += 2;
  if (x > 1) goto s2;
  x += 3;
  s1: 
  if (x > 2) goto s3;
  x += 5;
  s2:
  if (x < -9) goto s1;
  x += 7;
  return x;
}

int
main ()
{
  printf("%d\n", foo(1));
}

