//------------------------------------------------------------------------------
//
// Example for range-based natural numbers generator
//
// see natseq.cc for how to compile
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <iostream>

#include "generator.hpp"

template <typename T> range_gen<T> sequence(T start, T fin, T step) {
  for (T num = start; num < fin; num += step)
    co_yield num;
}

int main() {
  for (int i : sequence(0, 10))
    std::cout << i << " ";
  std::cout << std::endl;
}