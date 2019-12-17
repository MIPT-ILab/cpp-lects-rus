#include <cassert>
#include <chrono>
#include <iostream>

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;

#include "generator.hpp"

generator<int> fibs_modulo(int m) {
  int a = 0;
  int b = 1;
  for (;;) {
    co_yield a;
    int tmp = a;
    a = b;
    b = (tmp + a) % m;
  }
}

int
main() {
  unsigned long long k = 0; int m = 0;
  std::cin >> k >> m;
  
  assert(k > 1);
  assert(m > 1);
  
  std::cout << "Measuring coroutine: " << std::endl;
  auto tstart = high_resolution_clock::now();
  auto gen = fibs_modulo(m);
  for (unsigned long long i = 0; i < k; ++i)
    gen.move_next();
  auto tfin = high_resolution_clock::now();

  std::cout << duration_cast<milliseconds>(tfin - tstart).count() << std::endl;
}