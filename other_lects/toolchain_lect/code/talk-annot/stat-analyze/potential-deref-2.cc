#include <iostream>

int foo(const int *x) {
  return *x;
}

int main() {
  int t = 2;
  foo(&t);
  int x;
  std::cin >> x;
  if (x < 3) {
    foo(nullptr);
  }
}

