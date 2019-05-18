#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { ARRSZ = 32000, NITER = 100000 };

unsigned long long gsum;

static inline __attribute__ ((always_inline))
int f(int *arr, int j) {
  if (arr[j] > 100)
    arr[j] = 0;
  arr[j] += 1;
  gsum += arr[j]; 
}

int measure(int *arr, int len) {
  int i, j;
  clock_t start, finish;
  gsum = 0;
  int l8 = len / 8;

  start = clock();

#if LOCAL
  for (i = 0; i < NITER; ++i)
    for (j = 0; j < len; ++j)
      f(arr, j);
#else  
  for (i = 0; i < NITER; ++i) {
    for (j = 0; j < l8; ++j)
      f(arr, j);
    for (j = l8; j < 2*l8; ++j)
      f(arr, j);
    for (j = 2*l8; j < 3*l8; ++j)
      f(arr, j);
    for (j = 3*l8; j < 4*l8; ++j)
      f(arr, j);
    for (j = 4*l8; j < 5*l8; ++j)
      f(arr, j);
    for (j = 5*l8; j < 6*l8; ++j)
      f(arr, j);
    for (j = 6*l8; j < 7*l8; ++j)
      f(arr, j);
    for (j = 7*l8; j < 8*l8; ++j)
      f(arr, j);
  }
#endif  

  finish = clock();
  return (finish - start);
}

int
main () {
  int i, data[ARRSZ];
  double elapsed;  

  for (i = 0; i < ARRSZ; ++i)
    data[i] = rand() % 256;

  elapsed = measure(data, ARRSZ);
  printf("elapsed time: %lf\n", elapsed / CLOCKS_PER_SEC);
}
