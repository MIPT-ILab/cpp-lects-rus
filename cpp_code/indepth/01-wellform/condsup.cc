#include <iostream>

struct S {
  int x, y;
  virtual ~S() = default;
};

int main() {
  std::cout << offsetof(S, x) << std::endl;
}
