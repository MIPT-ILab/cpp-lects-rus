#include <math.h>
#include <stdio.h>
#include <xmmintrin.h>

double rsqrt(double x) {
  return _mm_rsqrt_sd(x);
//  return 1 / sqrt(x);
}

int main() {
  double x = rsqrt(2.0);
  printf("%lf\n", x);
}

