#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { ARRSZ = 2000, NITER = 500 };

unsigned long long gsum;

int measure(int (*arr)[ARRSZ], int len) {
  int i, j, k;
  clock_t start, finish;
  unsigned long long sum = 0;

  start = clock();

  for (k = 0; k < NITER; ++k) {
#if defined(REVERSE) 
    for (i = 0; i < ARRSZ; ++i)
      for (j = 0; j < len; ++j) 
        sum += arr[i][j];
#else    
    for (j = 0; j < len; ++j) 
      for (i = 0; i < ARRSZ; ++i)
        sum += arr[i][j];
#endif
  }

  gsum = sum;
  finish = clock();
  return (finish - start);
}

int
main () {
  int i;
  double elapsed;
  
  int (*arr)[ARRSZ] = (int (*)[ARRSZ]) malloc(ARRSZ * ARRSZ * sizeof(int));

  for (i = 0; i < 100; ++i)
    arr[rand() % ARRSZ][rand() % ARRSZ] = i;

#if defined(REVERSE)
  printf("reversing loop order\n");
#else  
  printf("normal loop order\n");
#endif
  elapsed = measure(arr, ARRSZ);

  printf("elapsed time: %lf\n", elapsed / CLOCKS_PER_SEC);
}
