#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;

std::atomic<long long> a{0}, b{0};

// a is always > b
void chase() {
  for (;;) {
    a++;
    b++;
  }
}

// check that a > b
void check() {
  for (;;) {
    long long bval = b;
    long long aval = a;
    if (aval < bval)
      cout << "Wrong: " << aval << " " << bval << endl;
  }
}

int main() {
  std::thread t1{chase};
  std::thread t2{check};
  t1.detach();
  t2.detach();
  std::this_thread::sleep_for(std::chrono::seconds(3));
}
