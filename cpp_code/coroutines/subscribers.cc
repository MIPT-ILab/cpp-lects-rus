//------------------------------------------------------------------------------
//
// Example for subscribers
//
// see hellocoro.cc for build instructions
//
//------------------------------------------------------------------------------
//
// This file is licensed after LGPL v3
// Look at: https://www.gnu.org/licenses/lgpl-3.0.en.html for details
//
//------------------------------------------------------------------------------

#include <chrono>
#include <iostream>
#include <thread>

#include "resumable.hpp"

#ifndef NATLST
#include "event-lst.hpp"
#else
#include "event-natlst.hpp"
#endif

int g_value;
evt_awaiter_t g_evt;

void producer() {
  std::cout << "Producer started" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  g_value = 42;
  std::cout << "Value ready" << std::endl;
  g_evt.set();
}

resumable_no_own consumer1() {
  std::cout << "Consumer1 started" << std::endl;
  co_await g_evt;
  std::cout << "Consumer1 resumed" << std::endl;
}

resumable_no_own consumer2() {
  std::cout << "Consumer2 started" << std::endl;
  co_await g_evt;
  std::cout << "Consumer2 resumed" << std::endl;
}

resumable_no_own consumer3() {
  std::cout << "Consumer3 started" << std::endl;
  co_await g_evt;
  std::cout << "Consumer3 resumed" << std::endl;
  co_await g_evt;
  std::cout << "Consumer3 resumed again" << std::endl;
}

int main() {
  consumer1();
  consumer2();
  consumer3();
  producer();
  consumer1();
  producer();
}
