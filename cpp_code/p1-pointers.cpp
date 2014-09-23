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
  int *p = y;
  int t = *(y + 3);
  return p[t];
}

