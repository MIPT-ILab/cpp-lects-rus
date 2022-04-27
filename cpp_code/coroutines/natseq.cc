//------------------------------------------------------------------------------
//
// Example for natural numbers generator
//
// > cl -await -EHsc natseq.cc
// > clang++ -fcoroutines-ts -std=c++20 -stdlib=libc++ natseq.cc
// > g++-10 -fcoroutines -std=c++20 natseq.cc
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

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
