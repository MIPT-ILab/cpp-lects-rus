#include <cassert>
#include <chrono>
#include <iostream>

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;

struct fibs_modulo_t {
  int a_ = 0, b_ = 1, m_;

  fibs_modulo_t(int m) : m_{m} {}

  int next() {
    int tmp = a_;
    a_ = b_;
    b_ = (tmp + a_) % m_;
    return tmp;
  }
};

int main() {
  unsigned long long k = 0;
  int m = 0;
  std::cin >> k >> m;

  assert(k > 1);
  assert(m > 1);

  std::cout << "Measuring struct: " << std::endl;
  auto tstart = high_resolution_clock::now();
  fibs_modulo_t fm{m};
  for (unsigned long long i = 0; i < k; ++i)
    fm.next();
  auto tfin = high_resolution_clock::now();

  std::cout << duration_cast<milliseconds>(tfin - tstart).count() << std::endl;
}