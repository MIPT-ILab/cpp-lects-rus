// simple factorial program, to illustrated convoluted debug info

#include <assert.h>
#include <stdio.h>

int fact(int x) {
  assert(x > 0);
  if (x < 3)
    return x;
  return fact(x - 1) * x;
}

int main() {
  int f5 = fact(5);
  printf("5! = %d\n", f5);
}

