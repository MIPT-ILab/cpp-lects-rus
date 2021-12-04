// integer power in logarithmic time

#include "mypow-1.h"

static unsigned is_odd(unsigned k) {
  return ((k % 2) == 1);
}

unsigned long long ipow (unsigned n, unsigned k) {
  unsigned long long mult, prod;
  if (n == 0 || n == 1 || k == 1) return n;
  if (k == 0) return 1;
  mult = n; 
  prod = 1;
  while (k > 0) {
    if (is_odd(k))
      prod *= mult;
    mult *= mult;
    k = k / 2;
  }
  return prod;
}
