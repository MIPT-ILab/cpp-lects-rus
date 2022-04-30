//------------------------------------------------------------------------------
//
// Example for cacncellables
//
// Try:
// > clang++ -fcoroutines-ts -std=c++20 -stdlib=libc++ cancellable.cc
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <chrono>
#include <iostream>
#include <thread>

#include "coroinclude.hpp"
#include "resumable.hpp"

resumable_cancelable foo() {
  for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
    co_await coro::suspend_always();
  }
}

int main() {
  auto f = foo();
  f.resume();
  f.resume();
  f.resume();
  std::cout << "Cancel point" << std::endl;
  f.cancel();
}