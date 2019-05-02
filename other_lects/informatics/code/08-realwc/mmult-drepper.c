#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { BIG_AX = 2000, BIG_AY = 1600, BIG_BY = 1200 };
enum { L1_LINE_SIZE = 64 };

// A[AX][AY] * B[AY][BY] = C[AX][BY]
void matrix_mult_drepper(const int *A, const int *B, int *C, 
                         int AX, int AY, int BY) {
  int SM = L1_LINE_SIZE / sizeof (int), i, j, k, i2, j2, k2;
  const int *rmul1, *rmul2;
  int *rres;

  assert(A != NULL && B != NULL && C != NULL);
  assert(AX > 0 && AY > 0 && BY > 0);
  assert((AX % SM) == 0 && (AY % SM) == 0 && (BY % SM) == 0);
  
  for (i = 0; i < AX; i += SM)
    for (j = 0; j < BY; j += SM)
      for (k = 0; k < AY; k += SM)
        for (i2 = 0, rres = &C[i * BY + j], rmul1 = &A[i * AY + k];
             i2 < SM; ++i2, rres += BY, rmul1 += AY)
          for (k2 = 0, rmul2 = &B[k * BY + j];
               k2 < SM; ++k2, rmul2 += BY)
            for (j2 = 0; j2 < SM; ++j2)
              rres[j2] += rmul1[k2] * rmul2[j2];  
}

void matrix_rand_init(int *arr, int sz) {
  srand(time(NULL));
  for (int i = 0; i < sz; ++i)
    arr[i] = (rand() % 20) - 10;
}

int
main () {
  clock_t start, fin;
  double diff;
  
  int (*a)[BIG_AY] = (int (*)[BIG_AY]) malloc(BIG_AX * BIG_AY * sizeof(int));
  int (*b)[BIG_BY] = (int (*)[BIG_BY]) malloc(BIG_AY * BIG_BY * sizeof(int)); 
  int (*c)[BIG_BY] = (int (*)[BIG_BY]) malloc(BIG_AX * BIG_BY * sizeof(int));
  
  start = clock();
  matrix_mult_drepper(&a[0][0], &b[0][0], &c[0][0], BIG_AX, BIG_AY, BIG_BY);
  fin = clock();
  
  diff = (double)(fin - start) / CLOCKS_PER_SEC;
  printf("Elapsed: %lg seconds\n", diff);
  
  free(c);
  free(b);
  free(a);
}
