#include <future>
#include <iostream>
#include <thread>
#include <utility>

int main() {
  auto divi = [](auto a, auto b) {
    if (b == 0)
      throw std::overflow_error("Divide by zero");
    return a / b;
  };

#if defined(EXC)
  std::future<int> f = std::async(divi, 30, 0);
#else
  std::future<int> f = std::async(divi, 30, 5);
#endif

  try {
    auto x = f.get();
    std::cout << "result: " << x << std::endl;
  } catch (std::exception &e) {
    std::cout << "exception: " << e.what() << std::endl;
  }
}
