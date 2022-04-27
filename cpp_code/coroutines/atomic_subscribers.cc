// cl -await -EHsc subscribers.cc
// clang++-9 -std=c++2a -stdlib=libc++ subscribers.cc

#include <chrono>
#include <iostream>
#include <thread>

#include "resumable.hpp"

#include "event-atlst.hpp"

std::atomic<int> g_value;
evt_awaiter_t g_evt;

void producer() {
  printf("p");
  std::this_thread::sleep_for(std::chrono::seconds(1));
  g_value = 42;
  printf("v");
  g_evt.set();
}

resumable_no_own consumer(int i) {
  printf("s");
  co_await g_evt;
  printf("r");
}

int main() {
  std::thread t1{consumer, 1};
  std::thread t2{consumer, 2};
  std::thread t3{consumer, 3};
  std::thread p{producer};
  p.join();
  t1.join();
  t2.join();
  t3.join();
  printf("\n");
}
