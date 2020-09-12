#include <cassert>
#include <iostream>

int foo(int* a, int len) {
  assert ((a != nullptr) && (len > 1));
  return a[len/2];
}

int main() {
  int *pg = new int[100];
  std::cout << foo(pg, 220) << std::endl;
  delete [] pg;
}

