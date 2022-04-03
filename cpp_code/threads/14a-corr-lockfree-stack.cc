#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <vector>

#include "sptr-stack.hpp"

namespace chr = std::chrono;

slist_t<int> s;

void producer(int num, int ntasks) {
  for (int i = 0; i < ntasks; ++i)
    s.push_front(i);
}

void consumer(int num, int ntasks) {
  for (int i = 0; i < ntasks; ++i)
    s.pop_front();
}

constexpr int NTHR = 10;

// shall be ok with 1000000
constexpr int NTASKS = 10000;

int main(int argc, char **argv) {
  auto nthr = NTHR;
  auto ntasks = NTASKS;

  if (argc > 1)
    nthr = std::stoi(argv[1]);

  if (argc > 2)
    ntasks = std::stoi(argv[2]);

  auto tstart = chr::high_resolution_clock::now();

  std::vector<std::thread> vp;
  for (int i = 0; i < nthr; ++i)
    vp.emplace_back([i, ntasks] { producer(i, ntasks); });  

  std::vector<std::thread> vc;
  for (int i = 0; i < nthr; ++i) {
    vc.emplace_back([i, ntasks] { consumer(i, ntasks); });
  }

  for (int i = 0; i < nthr; ++i) {
    vp[i].join();
    vc[i].join();
  }

  auto tfin = chr::high_resolution_clock::now();

  std::cout << chr::duration_cast<chr::milliseconds>(tfin - tstart).count() << std::endl;
}
