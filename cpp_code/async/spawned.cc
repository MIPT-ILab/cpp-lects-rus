#include <iostream>
#include <thread>

int main() {
  std::cout << "Main: " << std::this_thread::get_id() << "\n";
  std::thread t(
      [] { std::cout << "Spawned: " << std::this_thread::get_id() << "\n"; });
  t.join();
}
