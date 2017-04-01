char foo(char x = 0) { return x; }

int foo(int y = 5) { return y; }

long long foo(long long z = 0x0afff) { return z; }

int test01(void)
{
  char b[] = "abcdefgh", a, c;
  int i, j;
  a = b[i];
  c = j[b];
  return a+c;
}

int test02(void)
{
  int *p;
  int c;
  c = *p;  
  return c;
}

int test03(void)
{
  int p = 3;
  int *pp = (int *) p;
  return *pp;
}

#include "assert.h"

int test04(void)
{
  char a[] = "abcdefgh";
  char *b = "abcdefgh";
  assert (a[3] == b[3]);
}

int test05(void)
{
#if 0
  float a[] = {1.0, 2.0, 3.0}; /* ok */
  float *b = {1.0, 2.0, 3.0}; /* ka-boom! */
#endif
  return 0;
}

int f (int *x) { return x[0]; }

int buz(void)
{
  int a[9];
  assert(a[3] == *(a+3)); /* ok */
  return f(a); /* ok again */  
}

int test07(int **a)
{
  assert(a[3][4] == *(*(a+3) + 4)); /* ok */
}

float flt[][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0}}; /* ok */

int test08(void)
{
  int x = 5;
  int &xref = x;
  xref += 1;
  assert (x == 6);
  return xref;
}

int test09(void)
{
  int x[2] = {10, 20};
  int &xref = x[0];
  int *xptr = &x[0];
  xref += 1;
  xptr += 1;
  assert ((xref == 11) && (*xptr == 20));
  return 0;
}

int test10(void)
{
  struct S {}; struct S *t = new S; /* t = (struct S*) malloc (sizeof(struct S)); */
  delete t; /* free(t); */
  struct S *a = new S[5]; /* t = (struct S*) malloc (sizeof(struct S) * 5); */
  delete[] a; /* free(a); */
}

int test11(void)
{
  int *b, *c;
  char d;
  const int *e;
/*  int a = (int)(b) + (int)(c); boom in C++! */
/*  d = (char) a; boom in C++! */
  b = (int *) e;
  return 0;
}

int test12(void)
{
  char a;
  int b = static_cast<int>(a);
  return b;
}

int *test13(void)
{
  const int *a;
  int *b = const_cast<int*>(a);
  return b;
}

int *test14(void)
{
  int a;
  int *b = reinterpret_cast<int*>(a);
  return b;
}

char bar (char x) { return x; }
int bar (int y) { return y; }
long long bar (long long z) { return z; }



