#include <assert.h>
#include <stdio.h>

int foo() {
  int x, res;
  res = scanf("%d", &x);
  assert(res == 1);
  return x;
}

