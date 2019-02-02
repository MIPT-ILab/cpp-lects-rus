// integer power in logarithmic time

#include "mypow.h"

double expsq = 2.718281828 * 2.718281828;

static unsigned long long isqr(unsigned long long x) {
  return x * x;
}

unsigned long long ipow (unsigned n, unsigned k) {
  unsigned long long mult, prod;
  if (n == 0 || n == 1 || k == 1) return n;
  if (k == 0) return 1;
  mult = n; 
  prod = 1;
  while (k > 0) {
    if ((k % 2) == 1)
      prod *= mult;
    mult = isqr(mult);
    k = k / 2;
  }
  return prod;
}
