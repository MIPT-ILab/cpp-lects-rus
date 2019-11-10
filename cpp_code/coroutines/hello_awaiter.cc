#include <experimental/coroutine>
#include <iostream>

#include "resumable.hpp"

struct hello_awaiter {
  bool await_ready() const noexcept { return true; }
  void await_suspend(std::experimental::coroutine_handle<>) const noexcept {}
  void await_resume() const noexcept {
    std::cout << "Hello, world" << std::endl;
  }
};

resumable_no_wait hello() { 
  co_await hello_awaiter{};
}

int main() {
  hello();
}
