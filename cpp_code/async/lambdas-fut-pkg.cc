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

  std::packaged_task<int(int, int)> task{divi};
  std::future<int> f = task.get_future();
#if defined(EXC)
  std::thread t(std::move(task), 30, 0);
#else
  std::thread t(std::move(task), 30, 5);
#endif
  t.detach();

  try {
    auto x = f.get();
    std::cout << "result: " << x << std::endl;
  } catch (std::exception &e) {
    std::cout << "exception: " << e.what() << std::endl;
  }
}
