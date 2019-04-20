#include <assert.h>
#include <stdio.h>

unsigned gcd(unsigned x, unsigned y) {
  if (x < y) {
    int tmp = x;
    x = y;
    y = tmp;
  }
  int q = x % y;
  if (q == 0)
    return y;
  return gcd(y, q);
}

int main() {
  printf("%d\n", gcd(1769, 427));
}
