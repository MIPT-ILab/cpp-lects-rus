#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <vector>

#include "sptr-stack.hpp"

using std::cout;
using std::endl;
using std::make_unique;
using std::move;
using std::thread;
using std::unique_ptr;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::this_thread::sleep_for;

slist_t<unique_ptr<int>> s;

void producer(int num, int ntasks) {
  for (int i = 0; i < ntasks; ++i)
    s.push_front(make_unique<int>(i));
}

void consumer(int num, int ntasks) {
  for (int i = 0; i < ntasks; ++i)
    s.pop_front();
}

constexpr int NTHR = 10;

// almost no chances with 1000000
constexpr int NTASKS = 10000;

int main(int argc, char **argv) {
  auto nthr = NTHR;
  auto ntasks = NTASKS;

  if (argc > 1)
    nthr = std::stoi(argv[1]);

  if (argc > 2)
    ntasks = std::stoi(argv[2]);

  auto tstart = high_resolution_clock::now();

  vector<thread> vp;
  for (int i = 0; i < nthr; ++i) {
    vp.emplace_back([i, ntasks] { producer(i, ntasks); });
  }

  vector<thread> vc;
  for (int i = 0; i < nthr; ++i) {
    vc.emplace_back([i, ntasks] { consumer(i, ntasks); });
  }

  for (int i = 0; i < nthr; ++i) {
    vp[i].join();
    vc[i].join();
  }

  auto tfin = high_resolution_clock::now();

  cout << duration_cast<milliseconds>(tfin - tstart).count() << endl;
}
