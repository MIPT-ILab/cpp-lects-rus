#include <stdio.h>

static inline int foo() {
  printf("42");
}

int main() {
  foo();
}

