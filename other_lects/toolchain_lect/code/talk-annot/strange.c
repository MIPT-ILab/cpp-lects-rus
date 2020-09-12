#include <stdio.h>

struct S {
  int x[10];
};

struct S foo() {
  struct S ret = {{0, 1, 2, 3, 4, 5}};
  return ret;
}

int main() {
  struct S t = foo();
  printf("%d\n", t.x[3]);
}

