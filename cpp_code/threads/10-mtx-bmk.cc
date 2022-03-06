#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using std::atomic;
using std::atomic_flag;
using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

class my_mutex {
  atomic_flag flag{ATOMIC_FLAG_INIT};

public:
#if defined(MYMUT1)
  void lock() {
    while (flag.test_and_set())
      std::this_thread::yield();
  }
#endif

#if defined(MYMUT2)
  void lock() {
    unsigned i = 0;
    while (flag.test_and_set())
      if ((i++ % 128) == 0)
        std::this_thread::yield();
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
atomic<int> cnt{0};
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
constexpr int WORKLOAD = 50000000;
constexpr int THREAD_MIN = 1;
constexpr int THREAD_MAX = 20;

int main(int argc, char **argv) {
  auto wload = WORKLOAD;

  if (argc > 1)
    wload = std::stoi(argv[1]);

  for (int nthr = THREAD_MIN; nthr <= THREAD_MAX; ++nthr) {
    auto tstart = high_resolution_clock::now();

    vector<thread> threads(nthr);
    for (int i = 0; i < nthr; ++i)
      threads[i] = thread(&threadfunc, wload);

    for (int i = 0; i < nthr; ++i)
      threads[i].join();

    auto tfin = high_resolution_clock::now();
    cout << nthr << " " << duration_cast<milliseconds>(tfin - tstart).count()
         << endl;
    cnt = 0;
  }
}
