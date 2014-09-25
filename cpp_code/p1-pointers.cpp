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
  int z [][1] = {{1}, {2}};
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
