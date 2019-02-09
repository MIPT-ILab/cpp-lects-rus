#include <assert.h>
#include <stdio.h>

#include "common.h"

int
main () {
  int n, i, res;
  double sum = 0.0;
  res = scanf("%d", &n);
  assert (res == 1);
  
  for (i = 0; i < n; ++i) {
    struct triangle_t t;
    double sq;

    read_triangle(&t);
    sq = square(&t);
    sum += sq;    
  }
  
  printf("%lf\n", sum);
  return 0;
}

