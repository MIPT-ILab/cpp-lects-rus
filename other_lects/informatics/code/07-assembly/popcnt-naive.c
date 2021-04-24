#include <stdio.h>
#include <stdlib.h>

int
popcnt(unsigned n) {
 // int cnt;

 // __asm__("popcnt %0, %1":"=r"(cnt):"r"(n)); 
 
  return __builtin_popcount(n);
}

int
main() {
  const unsigned num = 2736523u;
  printf("Number = %x, popcnt = %d\n", num, popcnt(num));
}
