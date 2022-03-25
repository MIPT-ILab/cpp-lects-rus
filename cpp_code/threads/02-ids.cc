#include <iostream>
#include <thread>

int main() {
  std::cout << "Parent id: " << std::this_thread::get_id() << std::endl;
  std::thread t([]() {
    std::cout << "Spawned id: " << std::this_thread::get_id() << std::endl;
  });
  t.join();
}
