#include <stdio.h>

int mul(int x, int y, int z) {
  return x * y * z;
}

int main() {
  printf("mul: %d\n", mul(1 << 18, 1 << 19, 1 << 20));
}

