//------------------------------------------------------------------------------
//
// Example for simplest resumable function
//
// > cl -await -EHsc hellocoro.cc
// > clang++ -fcoroutines-ts -stdlib=libc++ hellocoro.cc
// > g++-10 -fcoroutines -std=c++20 hellocoro.cc
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <iostream>

#include "resumable.hpp"

resumable foo() {
  std::cout << "Hello" << std::endl;
  co_await coro::suspend_always();
  std::cout << "World" << std::endl;
}

int main() {
  auto t = foo();
  t.resume();
  std::cout << "Coroutine" << std::endl;
  t.resume();
}