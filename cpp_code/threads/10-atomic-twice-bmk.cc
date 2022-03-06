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

struct Counters {
  int a;
  int b;
};

#if defined(ATOMIC)
atomic<Counters> cnt{{0, 0}};
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
mutex m;

void threadfunc(int wload) {
  for (;;) {
    std::lock_guard<mutex> lk{m};
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

#if defined(ATOMIC) && defined(DETERMINE)
  cout << "LF: " << std::boolalpha << cnt.is_lock_free() << endl;
  exit(0);
#endif

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
    cnt = Counters{0, 0};
  }
}
