#include <cassert>
#include <iostream>

int g[100];

int foo(int* a, int len) {
  assert ((a != nullptr) && (len > 1));
  return a[len/2];
}

int main() {
  std::cout << foo(g, 220) << std::endl;
}

