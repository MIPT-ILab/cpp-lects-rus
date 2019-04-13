#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { ARRSZ = 32000, NITER = 50000 };

unsigned long long gsum;

int measure(int *arr, int len) {
  int i, j;
  clock_t start, finish;
  unsigned long long sum = 0;

  start = clock();
  for (i = 0; i < NITER; ++i)
    for (j = 0; j < len; ++j) 
      if (arr[j] > 128)
        sum += arr[j];    

  gsum = sum;
  finish = clock();
  return (finish - start);
}

#if defined(SORTED)
int less(const void *lhs, const void *rhs) {
  return *(int *)lhs - *(int *)rhs;
}
#endif

int
main () {
  int i, data[ARRSZ];
  double elapsed;  

  for (i = 0; i < ARRSZ; ++i)
    data[i] = rand() % 256;

#if defined(SORTED)
  printf("pre-sorting data\n");
  qsort(data, ARRSZ, sizeof(int), less);
#else
  printf("not pre-sorting data\n");
#endif

  elapsed = measure(data, ARRSZ);
  printf("elapsed time: %lf\n", elapsed / CLOCKS_PER_SEC);
}

