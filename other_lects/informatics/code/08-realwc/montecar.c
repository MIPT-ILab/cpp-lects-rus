#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { NOUTER = 10000, TOTALSZ = 200000 };

int *arr;

int
main () {
  clock_t start, finish;
  int N, i, j, k;

  for (N = 5; N < 10; N += 5) {
    int titer = TOTALSZ / N;
    arr = calloc(N, sizeof(int));
    start = clock();
    for (int k = 0; k < NOUTER; ++k)
      for (int i = 0; i < titer; ++i)
        for (int j = 0; j < N; ++j) {
          arr[j] += 1;
        }
    finish = clock();
    printf("%d\t%d\t", N * sizeof(int), finish - start);
    start = clock();
    for (int k = 0; k < NOUTER; ++k)
      for (int i = 0; i < titer; ++i)
        for (int j = 0; j < N; ++j)
          arr[(j * 167) % N] += 1;
    finish = clock();
    printf("%d\n", finish - start);
    free(arr);
  }

}