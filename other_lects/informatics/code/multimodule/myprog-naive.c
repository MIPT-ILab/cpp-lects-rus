#include <stdio.h>

unsigned long long ipow (unsigned n, unsigned k) {
  unsigned long long mult, prod;
  if (n == 0 || n == 1 || k == 1) return n;
  if (k == 0) return 1;
  mult = n;
  prod = 1;
  while (k > 0) {
    if ((k % 2) == 1)
      prod *= mult;
    mult *= mult;
    k = k / 2;
  }
  return prod;
}

int
main () {
  printf("3^7 == %llu\n", ipow(3, 7));
  printf("4^13 == %llu\n", ipow(4, 13));
  printf("17^6 == %llu\n", ipow(17, 6));
  return 0;
}
