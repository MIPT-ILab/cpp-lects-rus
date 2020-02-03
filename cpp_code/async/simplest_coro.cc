// cl -await -EHsc simplest_coro.cc

#include <experimental/coroutine>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

int main() {
  auto compute = []() -> std::future<int> { co_return 42; };

  auto f = compute();
  std::cout << f.get() << std::endl;
}