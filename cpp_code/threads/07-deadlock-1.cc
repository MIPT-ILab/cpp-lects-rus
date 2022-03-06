#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::lock_guard;
using std::mutex;
using std::thread;

template <typename T> struct holder {
  mutex lock_;
  T data_;
  holder(T data) : lock_{}, data_(data) {}
};

template <typename T> void swapholders(holder<T> &lhs, holder<T> &rhs) {
  if (&lhs == &rhs)
    return;

  lock_guard<mutex> lk1{lhs.lock_};
  std::this_thread::sleep_for(std::chrono::seconds(1));
  lock_guard<mutex> lk2{rhs.lock_};

  std::swap(lhs.data_, rhs.data_);
}

int main() {
  holder<int> x(1), y(2);

  thread t1(swapholders<int>, std::ref(x), std::ref(y));
  thread t2(swapholders<int>, std::ref(y), std::ref(x));

  t1.join();
  t2.join();

  return 0;
}
