int foo(int x) 
{
  int a = (x += 0) + 3;
  return a;
}

int bar(int x) 
{
  int a = x +++++ x;
  return a;
}

int buz(int x) 
{
  int b = bar(b += foo(b));
  return b;
}

char *fst(void)
{
  char *p = "wikipedia";
  p[0] = 'W';
  return p;
}

void snd(int *a, int i)
{
  a[i] = i++;
}
