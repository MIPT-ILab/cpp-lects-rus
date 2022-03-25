#include <iostream>
#include <thread>

template <typename T> struct TD;


int main() {
  int result = 42;

  auto divi = [](auto&& result, auto a, auto b) { 
    result.get() = a / b;
  };

  std::thread t(divi, std::move(result), 30, 6);
  t.join();
  std::cout << "result: " << result << std::endl;
}
