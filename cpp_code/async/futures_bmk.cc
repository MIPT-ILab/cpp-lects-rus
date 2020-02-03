// cl -std:c++17 -EHsc -await -O2 futures_bmk.cc

#include <chrono>
#include <experimental/coroutine>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

#include "generator.hpp"

constexpr int NITER = 20000000;

using std::chrono::duration_cast;
using chrc = std::chrono::high_resolution_clock;
using cms = std::chrono::milliseconds;

int deferred_calc() {
  std::cout << "Event happened!\n";
  return 42;
}

generator<int> deferred_coro() {
  std::cout << "Event happened!\n";
  co_yield 42;
}

void show_resumable() {
  auto fut = std::async(std::launch::deferred, deferred_calc);
  std::cout << "Async deferred created\n";
  fut.get();
  
  auto fut2 = deferred_coro();
  std::cout << "Coro deferred created\n";
  fut2.move_next();
}

int g;

unsigned lfunc() {
  std::atomic_thread_fence(std::memory_order_seq_cst);
  return g;
}

generator<int> cfunc() {
  std::atomic_thread_fence(std::memory_order_seq_cst);
  co_yield g;
}

int main() {
  g = 42;
  unsigned res = 0;
  
  show_resumable();

  auto tstart = chrc::now();  
  for(int i = 0; i < NITER; ++i)
    res += lfunc();
  auto tfin = chrc::now();

  std::cout << "Plain result: " << res << std::endl;
  std::cout << "time: " << duration_cast<cms>(tfin - tstart).count() 
            << std::endl;
  
  tstart = chrc::now();  
  res  = 0;
  for(int i = 0; i < NITER; ++i)
    res += std::async(std::launch::deferred, lfunc).get();
  tfin = chrc::now();

  std::cout << "Async result: " << res << std::endl;
  std::cout << "time: " << duration_cast<cms>(tfin - tstart).count() 
            << std::endl;

  tstart = chrc::now();  
  res  = 0;
  for(int i = 0; i < NITER; ++i) {
    auto gen = cfunc();
    gen.move_next();
    res += gen.current_value();
  }
  tfin = chrc::now();

  std::cout << "Coro result: " << res << std::endl;
  std::cout << "time: " << duration_cast<cms>(tfin - tstart).count() 
            << std::endl;

}