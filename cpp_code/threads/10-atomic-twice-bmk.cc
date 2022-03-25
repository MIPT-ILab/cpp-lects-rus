#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

namespace chr = std::chrono;

struct Counters {
  int a, b;
};

#if defined(ATOMIC)
std::atomic<Counters> cnt{{0, 0}};
void threadfunc(int wload) {
  for (;;) {
    Counters cnl, cnn;
    do {
      cnl = cnt.load();
      if (cnl.a + cnl.b >= wload)
        return;
      cnn = cnl;
      cnn.a += 1;
      cnn.b += 2;
    } while (!cnt.compare_exchange_weak(cnl, cnn));
  }
}
#else
Counters cnt{0, 0};
std::mutex m;

void threadfunc(int wload) {
  for (;;) {
    std::lock_guard<std::mutex> lk{m};
    cnt.a += 1;
    cnt.b += 2;
    if (cnt.a + cnt.b >= wload)
      break;
  }
}
#endif

// number of tasks
constexpr int WORKLOAD = 50000000;
constexpr int THREAD_MIN = 1;
constexpr int THREAD_MAX = 20;

int main(int argc, char **argv) {
  auto wload = WORKLOAD;

  if (argc > 1)
    wload = std::stoi(argv[1]);

#if defined(ATOMIC)
  std::cout << "counter lock free: " << std::boolalpha << cnt.is_lock_free()
            << std::endl;
#endif

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
    cnt = Counters{0, 0};
  }
}
