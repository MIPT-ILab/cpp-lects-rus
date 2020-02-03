#include <future>
#include <iostream>
#include <thread>
#include <utility>

int main() {
  std::promise<int> p;
  std::future<int> f = p.get_future();

  auto divi = [](auto &&result, auto a, auto b) {
    try {
      if (b == 0)
        throw std::overflow_error("Divide by zero");
      result.set_value(a / b);
    } catch (...) {
      result.set_exception(std::current_exception());
    }
  };

  std::thread t(divi, std::move(p), 30, 0);
  t.detach();

  try {
    auto x = f.get();
    std::cout << "result: " << x << std::endl;
  } catch (std::exception &e) {
    std::cout << "exception: " << e.what() << std::endl;
  }
}
