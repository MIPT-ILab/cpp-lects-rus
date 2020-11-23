#include <stdio.h>
#include <stdlib.h>

int foo() {
  int gcnt = 0;
  for (;;) {
    int *p = malloc(1 << 30);
    gcnt += 1;
    printf("counter: %d\n", gcnt);
    if (gcnt == -1) break;
  }
}

int main() {
  foo();
}

