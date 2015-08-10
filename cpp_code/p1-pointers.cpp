typedef int unsized_arr_t[];

int 
foo (int x)
{
  return x;
}

int 
bar (int x)
{
  int (*pfoo) (int) = &foo;
  return pfoo (x);
}

int 
baz (int x)
{
  int y[10] = {4, x};
  // int z [][1] = {{1}, {2}};
  int *p = y;
  int t = *(y + 3);
  return p[t];
}

int
err (int x[], int *y)
{
  int a = 5;
  y = x;
  x = &a;
  return *x;
}

int
callee (int x[16])
{
  return x[15] + x[0];
}

int
caller (int *x)
{
  return callee (x);
}

int 
caller2 (unsized_arr_t x)
{
  return callee (x);
}

#if 0
unsized_arr_t
caller3 (int x)
{
  return &x;
}
#endif

#include <stddef.h>

ptrdiff_t
lr (void)
{
  int arr[] = {0, 1, 2, 3, 4, 5};
  int a = 0; 
  int *b = &arr[0];
  int *c = b + a; /* ok */
  int *d = a + b; /* ok */
//  int *e = c + d; /* error */
  ptrdiff_t f = c - d; /* ok */
  int *g = c - a; /* ok */
//  int *h = a - c; /* error */
  return f;
}

