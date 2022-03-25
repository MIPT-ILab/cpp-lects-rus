#include <future>
#include <iostream>
#include <thread>
#include <utility>

int main() {
  std::promise<int> p;
  std::future<int> f = p.get_future();

  auto divi = [](auto &&result, auto a, auto b) { 
    result.set_value(a / b);
  };

  std::thread t(divi, std::move(p), 30, 6);
  t.detach();

  std::cout << "result: " << f.get() << std::endl;
}
