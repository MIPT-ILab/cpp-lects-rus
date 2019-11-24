// cl -await -EHsc hellocoro.cc

#include <iostream>

#include "resumable.hpp"

resumable_no_wait foo() {
  std::cout << "Hello" << std::endl;
  co_await std::experimental::suspend_never();
  std::cout << "World" << std::endl;
}

int main() { foo(); }