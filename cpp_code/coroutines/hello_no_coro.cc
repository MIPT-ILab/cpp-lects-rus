//------------------------------------------------------------------------------
//
// Example for simple alternative awaiter object: never suspend
//
// see hellocoro.cc for build instructions
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <iostream>

#include "resumable.hpp"

resumable_no_wait foo() {
  std::cout << "Hello" << std::endl;
  co_await coro::suspend_never();
  std::cout << "World" << std::endl;
}

int main() { foo(); }