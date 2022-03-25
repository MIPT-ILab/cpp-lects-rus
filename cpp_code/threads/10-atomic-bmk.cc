#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace chr = std::chrono;

#if defined(ATOMIC)
std::atomic<int> cnt{0};
void threadfunc(int wload) {
  for (;;) {
    cnt += 1;
    if (cnt >= wload)
      break;
  }
}
#else
int cnt = 0;
std::mutex m;

void threadfunc(int wload) {
  for (;;) {
    std::lock_guard<std::mutex> lk{m};
    cnt += 1;
    if (cnt >= wload)
      break;
  }
}
#endif

// number of tasks
constexpr int WORKLOAD = 50000000;
constexpr int THREAD_MIN = 1;
constexpr int THREAD_MAX = 10;

int main(int argc, char **argv) {
  auto wload = WORKLOAD;

  if (argc > 1)
    wload = std::stoi(argv[1]);

  for (int nthr = THREAD_MIN; nthr <= THREAD_MAX; ++nthr) {
    auto tstart = chr::high_resolution_clock::now();

    std::vector<std::thread> threads(nthr);
    for (int i = 0; i < nthr; ++i)
      threads[i] = std::thread(&threadfunc, wload);

    for (int i = 0; i < nthr; ++i)
      threads[i].join();

    auto tfin = chr::high_resolution_clock::now();
    std::cout << nthr << " "
              << chr::duration_cast<chr::milliseconds>(tfin - tstart).count()
              << std::endl;
    cnt = 0;
  }
}
