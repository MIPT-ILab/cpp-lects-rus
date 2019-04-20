#include <stdio.h>
#include <stdlib.h>

int
popcnt(unsigned n) {
#if !defined(HAVE_BUILTIN_POPCNT)
  unsigned mask = 1;
  int cnt = 0;
  
  for (;;) {
    if ((n & mask) == mask)
      cnt += 1;
    if (mask == (1u << 31))
      break;
    mask = mask << 1;
  }
  
  return cnt;
#else
  return __builtin_popcount(n);
#endif  
}

int
main() {
  const unsigned num = 2736523u;
  printf("Number = %x, popcnt = %d\n", num, popcnt(num));
}
