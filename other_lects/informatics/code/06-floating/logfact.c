#include <math.h>
#include <stdio.h>

double
logFact(int n) {
  double sum = 0.0;
  for (int i = 2; i <= n; ++i)
    sum += log((double)i);
  return sum;
}

int
main() {
  double x; 
  double res = 2.245100430901328e+16;
  
  // via logFact
  x = exp(logFact(200) - logFact(190) - logFact(10));
  printf("200!/(190!*10!) = %lf\n", x);
  printf("rounding error = %lf\n", fabs(x - res));
  
  // via lgamma
  // x! = Г(x + 1)
  x = exp(lgamma(200.0 + 1.0) - lgamma(190.0 + 1.0) - lgamma(10.0 + 1.0));
  printf("200!/(190!*10!) = %lf\n", x);
  printf("rounding error = %lf\n", fabs(x - res));
}