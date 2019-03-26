#include <stdio.h>

int foo() {
  printf("%s\n", "foo");
  return 0;
}

int bar() {
  printf("%s\n", "bar");
  return 1;
}

int buz(int x, int y) {
  printf("%s %d %d\n", "buz", x, y);
}

int main() {
  buz(foo(), bar());
}