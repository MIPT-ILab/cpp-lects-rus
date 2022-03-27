#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace chr = std::chrono;

class my_mutex {
  std::atomic_flag flag{ATOMIC_FLAG_INIT};

public:
#if defined(MYMUT1)
  void lock() {
    while (flag.test_and_set())
      std::this_thread::yield();
  }
#endif

#if defined(MYMUT2)
  void lock() {
    while (flag.test_and_set());
  }
#endif

  bool try_lock() { return !flag.test_and_set(); }
  void unlock() { flag.clear(); }
};

#if defined(MYMUT1) || defined(MYMUT2)
using mtx = my_mutex;
#elif defined(STDMUT)
using mtx = std::mutex;
#elif defined(ATOMIC)
using mtx = void;
#else
using mtx = std::mutex;
#error "You shall define something"
#endif

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
mtx m;

void threadfunc(int wload) {
  for (;;) {
    {
      std::lock_guard<mtx> lk{m};
      cnt += 1;
      if (cnt >= wload)
        break;
    }
  }
}
#endif

// number of tasks
constexpr int WORKLOAD = 40000000;
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
