// cl -await -EHsc hellocoro.cc

#include <iostream>

#include "resumable.hpp"

resumable foo() {
  std::cout << "Hello" << std::endl;
  co_await std::experimental::suspend_always();
  std::cout << "World" << std::endl;
}

int main() {
  auto t = foo();
  t.resume();
  t.resume();
}