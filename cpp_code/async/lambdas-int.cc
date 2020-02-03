#include <iostream>
#include <thread>

template <typename T> struct TD;

int main() {
  int result;

  auto divi = [](int &result, int a, int b) { result = a / b; };
  std::thread t(divi, std::ref(result), 30, 6);
  t.join();
  std::cout << "result: " << result << std::endl;
}
