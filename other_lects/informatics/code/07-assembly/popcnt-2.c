#include <stdio.h>
#include <stdlib.h>

int
popcnt(unsigned n) {
  return __builtin_popcount(n);
}

int
main() {
  const unsigned num = 2736523u;
  printf("Number = %x, popcnt = %d\n", num, popcnt(num));
}
