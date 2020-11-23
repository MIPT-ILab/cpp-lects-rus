#include <stdio.h>
#include <stdlib.h>

int gcnt;

int foo(int *p) {
  int arr[1024 * 8];
  gcnt += 1;
  printf("counter: %d\n", gcnt);
  foo(arr);
}

int main() {
  foo(0);
}

