#include <stdio.h>
#include <math.h>

unsigned long long fibd(unsigned n) {
  double phi = (1.0 + sqrt(5.0))/ 2.0;
  return round(pow(phi, n) / sqrt(5.0));
}

int main () {
  int i;
  for (i = 30; i < 46; ++i) 
    printf("%llu ", fibd(i * 2));
  printf("\n");
}
