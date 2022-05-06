//------------------------------------------------------------------------------
//
// Example for optional
//
// Try:
// > clang++ -fcoroutines-ts -std=c++20 -stdlib=libc++ -O2 optional.cc
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <iostream>

#include "resumable.hpp"

std::optional<int> five() { return 5; }

std::optional<int> six() { return 6; }

std::optional<int> empty() { return std::nullopt; }

resume_optional<int> sum() {
  auto a = co_await five(); // 5 or return to caller with nullopt
  auto b = co_await six();  // 6 or return to caller with nullopt

  co_return a + b; // return sum
}

resume_optional<int> sum2() {
  auto a = co_await five();
  auto b = co_await empty();

  co_return a + b;
}

std::ostream &operator<<(std::ostream &os, const std::optional<int> &opt) {
  if (!opt)
    os << "(empty)";
  else
    os << opt.value();
  return os;
}

int main() {
  auto opt = sum();
  std::cout << "sum: " << opt.current_value() << std::endl;

  auto opt2 = sum2();
  std::cout << "sum2: " << opt2.current_value() << std::endl;
}
