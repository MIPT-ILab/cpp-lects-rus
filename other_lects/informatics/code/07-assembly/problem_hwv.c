#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

enum { XSZ = 2000, YSZ = 2000 };

short vect[YSZ];
short matr[YSZ][XSZ];
short result[XSZ];

void mult_vm() {
  int i, j;
  
  for (i = 0; i < XSZ; ++i) {
    int acc = 0;
    for (j = 0; j < YSZ; ++j)
      acc += vect[j] * matr[j][i];
    result[i] = acc;
  }
}

int
main() {
  int i, j;

  for (i = 0; i < YSZ; ++i)
    vect[i] = rand() % 10;

  for (i = 0; i < XSZ; ++i)
    for (j = 0; j < YSZ; ++j)
      matr[j][i] = rand() % 10;
  
  mult_vm();
}