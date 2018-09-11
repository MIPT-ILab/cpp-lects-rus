#include <assert.h>
#include <stdio.h>

unsigned pow_mod (unsigned n, unsigned k, unsigned m) {
  unsigned long long mult, prod;
  assert (m > 1);
  if (k == 0) return 1;
  mult = n % m; 
  prod = 1;
  while (k > 0) {
    if ((k % 2) == 1) { 
      prod = (prod * mult) % m; k = k - 1; 
    } 
    else { 
      mult = (mult * mult) % m; k = k / 2;
    }
  }
  return prod;
}

int main () {
  printf("%d\n", pow_mod(2018, 2018, 20));
}