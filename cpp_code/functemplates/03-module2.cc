#include <cassert>
#include <iostream>

// ---- suppose it is from header

int foo();

template <typename T> 
T do_nth_power(T x, T acc, unsigned n);

// ----

int nth_power(int x, unsigned n) {
  if (x < 2 || n == 1u) return x;
  return do_nth_power<int>(x, 1, n);
}

int
foo () {
  assert (nth_power(0, 10) == 0);
  assert (nth_power(1, 11) == 1);
  assert (nth_power(2, 11) == (1 << 11));
  assert (nth_power(3, 0) == 1);
  assert (nth_power(3, 3) == 27);
  assert (nth_power(3, 15) == 14348907);
}
