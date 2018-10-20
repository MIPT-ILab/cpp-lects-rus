#include <array>
#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

using std::array;
using std::cout;
using std::endl;
using std::lock_guard;
using std::mutex;
using std::thread;
using std::try_lock;
using std::pair;

int overall_count = 0;
array<int, 2> counter = {0, 0};
array<mutex, 2> mut;
mutex mcout;

void increment_loop (int idx, const char *desc) {
  for (int i = 0; i < 10; ++i) {
    {
      lock_guard<mutex> lock {mut[idx]};
      ++counter[idx];
      {
        lock_guard<mutex> lcout {mcout};
        cout << desc << ": " << counter[idx] << endl;
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void update_loop () {
  while (overall_count < 20) {
    int result = try_lock(mut[0], mut[1]); 
    if (result == -1) {
      lock_guard<mutex> lock1 {mut[0], std::adopt_lock};
      lock_guard<mutex> lock2 {mut[1], std::adopt_lock};
      overall_count = counter[0] + counter[1];
      {
        lock_guard<mutex> lcout {mcout};
        cout << "overall: " << overall_count << endl;
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

int
main () {
  thread incfoo {increment_loop, 0, "foo"};
  thread incbar {increment_loop, 1, "bar"};
  thread updall {update_loop};

  incfoo.join();
  incbar.join();
  updall.join();
}

