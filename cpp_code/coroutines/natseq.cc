#include <iostream>

#include "generator.hpp"

generator<int> natural_nums() {
  int num = 0;
  for (;;) {
    co_yield num;
    num += 1;
  }
}

int main() {
  auto nums = natural_nums();

  nums.move_next();
  auto y = nums.current_value();
  nums.move_next();
  auto z = nums.current_value();

  std::cout << y << " " << z << std::endl;
}