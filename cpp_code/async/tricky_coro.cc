// cl -await -EHsc simplest_coro.cc

#include <chrono>
#include <experimental/coroutine>
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
  std::this_thread::sleep_for(cms(1000));
  return x * 2;
}

int main() {
  auto compute = []() -> std::future<int> {   
    int result = co_await std::async(std::launch::async, get_result);
    std::cout << "awake 1" << std::endl;
    result = co_await std::async(std::launch::async, process_result, result);
    std::cout << "awake 2" << std::endl;
    co_return result;
  };

  auto tstart = chrc::now();

  auto f = compute();
  std::cout << "point 1" << std::endl;  

  // some heavy task
  std::this_thread::sleep_for(cms(1000));
  
  std::cout << "point 2" << std::endl; 

  auto result = f.get();
  auto tfin = chrc::now();

  std::cout << "result: " << result << std::endl;
  std::cout << "time: " << duration_cast<cms>(tfin - tstart).count()
            << std::endl;
}
