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

template <typename T, typename U> auto zip(T t, U u) {
  auto itt = t.begin(), itte = t.end();
  auto itu = u.begin(), itue = u.end();
  for (; itt != itte && itu != itue; ++itt, ++itu)
    co_yield std::make_pair(*itt, *itu);
}

template <typename T> range_gen<T> sequence(T start, T fin, T step) {
  for (T num = start; num < fin; num += step)
    co_yield num;
}

int main() {
  for (auto [i, j] : zip(sequence(25, 40, 3), sequence(5, 20, 3)))
    std::cout << "(" << i << " " << j << ") ";
  std::cout << std::endl;
}