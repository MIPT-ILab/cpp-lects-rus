#include <stdio.h>

int __attribute__((noinline))
__attribute__ ((fastcall))
foo(int x, int y, int z, int v, int u, int w, int n) {
  return (x + y) * z + v - u * (w - n);
}

int main() {
  int n = foo(1, 2, 3, 4, 5, 6, 7);
  printf("%d\n", n);
}

