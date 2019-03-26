#include <stdio.h>

int foo(int x) {
  return x << 2;
}

int main(void) {
  printf("%d\n", foo(-1));
}
