// cl -await -EHsc subscribers.cc

#include <chrono>
#include <iostream>
#include <thread>

#include "resumable.hpp"

resumable_cancelable foo() {
  for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
    co_await std::experimental::suspend_always();
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