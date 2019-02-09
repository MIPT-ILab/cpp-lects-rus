#include <atomic>
#include <cassert>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using std::atomic;
using std::atomic_flag;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::vector;

#if defined(ATOMIC)
atomic<int> cnt{0};
void threadfunc(int wload) {  
  for (;;) {
    cnt +=  1;
    if (cnt >= wload)
      break;
  }
}
#else
int cnt = 0;
mutex m;

void threadfunc(int wload) {
  for (;;) {
    std::lock_guard<mutex> lk{m};
    cnt +=  1;
    if (cnt >= wload)
      break;
  }
}
#endif

// number of tasks
constexpr int WORKLOAD = 50000000;
constexpr int NTHREADS = 3; 
constexpr int NATTEMPTS = 10; 

int
main(int argc, char **argv) {
  auto wload = WORKLOAD;
  auto nthr = NTHREADS;
  auto natt = NATTEMPTS;

  if (argc > 1)
    wload = std::stoi(argv[1]);

  if (argc > 2)
    nthr = std::stoi(argv[2]);

  if (argc > 3)
    natt = std::stoi(argv[3]);
  
  for (int attidx = 0; attidx < natt; ++attidx) {
    auto tstart = high_resolution_clock::now();

    vector<thread> threads(nthr);
    for (int i = 0; i < nthr; ++i)
      threads[i] = thread(&threadfunc, wload);

    for (int i = 0; i < nthr; ++i)
      threads[i].join();
  
    auto tfin = high_resolution_clock::now();
    cout << attidx << " " << duration_cast<milliseconds>(tfin - tstart).count() << endl;
    cnt = 0;
  }
}
