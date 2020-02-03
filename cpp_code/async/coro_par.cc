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

int get_first() {
  // some heavy task
  std::this_thread::sleep_for(cms(1000));
  return 21;
}

int get_second() {
  // some heavy task
  std::this_thread::sleep_for(cms(1000));
  return 21;
}

int main() {
  auto compute = []() -> std::future<int> {
    int fst = co_await std::async(std::launch::async, get_first);
    int snd = co_await std::async(std::launch::async, get_second);
    co_return fst + snd;
  };

  auto tstart = chrc::now();

  auto f = compute();

  // some heavy task
  std::this_thread::sleep_for(cms(1000));

  auto result = f.get();
  auto tfin = chrc::now();

  std::cout << "result: " << result << std::endl;
  std::cout << "time: " << duration_cast<cms>(tfin - tstart).count()
            << std::endl;
}
