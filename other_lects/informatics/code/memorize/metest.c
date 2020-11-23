#include <stdio.h>
#include <stdlib.h>

int g;

int fact(int x) {
  int y = 1;
  if (x < 2) return y;
  return x * fact(x - 1);
}

int main() {
  int *ph = malloc(10);
  fact(10); 
}

