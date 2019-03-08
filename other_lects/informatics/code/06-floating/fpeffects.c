#include <fenv.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

unsigned 
as_uint(float f) 
{
  return *(unsigned *)&f;
}

void
test(float a, float b)
{
  unsigned au, bu, qu, pu;
  float q, p;

  printf("test for %.1g / %.1g\n", a, b);

  q = a / b;
  p = q * b;
  au = as_uint(a);
  bu = as_uint(b);
  qu = as_uint(q);
  pu = as_uint(p);

  printf("%x / %x == %x\n", au, bu, qu);
  printf("%x * %x == %x\n", qu, bu, pu);
  if (au != pu)
    printf("inexact detected\n");
}

int
main() 
{
  float a, b;
  while (scanf("%f%f", &a, &b) == 2)
    {
      printf("test upward:\n");
      fesetround(FE_UPWARD);
      test(a, b);
      printf("test downward:\n");
      fesetround(FE_DOWNWARD);
      test(a, b);
      printf("test nearest:\n");
      fesetround(FE_TONEAREST);
      test(a, b);
      printf("test tozero:\n");
      fesetround(FE_TOWARDZERO);
      test(a, b);
    }

  return 0;
}


