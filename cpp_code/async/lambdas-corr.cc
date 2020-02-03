#include <iostream>
#include <thread>

template <typename T> struct TD;

int main() {
  int result;

  auto divi = [](auto &&result, auto a, auto b) { result.get() = a / b; };
  std::thread t(divi, std::ref(result), 30, 6);
  t.join();
  std::cout << "result: " << result << std::endl;
}
