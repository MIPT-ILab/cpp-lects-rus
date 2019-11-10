// cl -await -EHsc subscribers.cc

#include <chrono>
#include <iostream>
#include <thread>

#include "resumable.hpp"
#include "eventawt.hpp"

int g_value;
evt_awaiter_t g_evt;

void producer() {
  std::cout << "Producer started" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  g_value = 42;
  std::cout << "Value ready" << std::endl;  
  g_evt.set();
}

resumable_no_wait consumer1() {
  std::cout << "Consumer1 started" << std::endl;
  co_await g_evt;
  std::cout << "Consumer1 resumed" << std::endl;
}

resumable_no_wait consumer2() {
  std::cout << "Consumer2 started" << std::endl;
  co_await g_evt;
  std::cout << "Consumer2 resumed" << std::endl;
}

resumable_no_wait consumer3() {
  std::cout << "Consumer3 started" << std::endl;
  co_await g_evt;
  std::cout << "Consumer3 resumed" << std::endl;
}

int main() {
  resumable_no_wait c1 = consumer1();
  resumable_no_wait c2 = consumer2();
  resumable_no_wait c3 = consumer3();
  producer();
}
