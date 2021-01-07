#include <iostream>

int foo(bool c) {
  int x, y;
  y = c ? x : 42;
  return y;
}

int main() {
  std::cout << foo(true) << std::endl;
}
