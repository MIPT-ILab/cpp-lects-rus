#include <stdio.h>

int foo() {
  printf("%s\n", "foo");
  return 14;
}

int bar() {
  printf("%s\n", "bar");
  return 42;
}

void buz(int x, int y) {
  printf("%d\n", x + y);
}

int main() {
  buz(foo(), bar());
}

