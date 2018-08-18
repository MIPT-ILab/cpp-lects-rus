#include <cassert>
#include <iostream>

template <typename T> 
T do_nth_power(T x, T acc, unsigned n);

unsigned nth_power(unsigned x, unsigned n) {
  if (x < 2u || n == 1u) return x;
  return do_nth_power<unsigned>(x, 1u, n);
}

template <typename T> 
T do_nth_power(T x, T acc, unsigned n) {
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
