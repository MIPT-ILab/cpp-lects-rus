#include <cassert>
#include <iostream>

unsigned nth_power(unsigned x, unsigned n) {
  unsigned acc = 1;
  if ((x < 2) || (n == 1)) return x;
  while (n > 0)
    if ((n & 0x1) == 0x1) { acc *= x; n -= 1; }
    else { x *= x; n /= 2; }  
  return acc;
}

int
main () {
  assert (nth_power(0, 10) == 0);
  assert (nth_power(1, 11) == 1);
  assert (nth_power(2, 11) == (1 << 11));
  assert (nth_power(3, 0) == 1);
  assert (nth_power(3, 3) == 27);
  assert (nth_power(3, 15) == 14348907);
}