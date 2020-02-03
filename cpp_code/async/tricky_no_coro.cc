#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

using std::chrono::duration_cast;
using chrc = std::chrono::high_resolution_clock;
using cms = std::chrono::milliseconds;

int get_result() {
  // some heavy task
  std::this_thread::sleep_for(cms(500));
  return 21;
}

int process_result(int x) {
  // some heavy task
  std::this_thread::sleep_for(cms(500));
  return x * 2;
}

int main() {
  auto tstart = chrc::now();
  auto f1 = std::async(get_result);

  // some heavy task
  std::this_thread::sleep_for(cms(1000));

  auto f2 = std::async(process_result, f1.get());
  auto result = f2.get();
  auto tfin = chrc::now();

  std::cout << "result: " << result << std::endl;
  std::cout << "time: " << duration_cast<cms>(tfin - tstart).count()
            << std::endl;
}
