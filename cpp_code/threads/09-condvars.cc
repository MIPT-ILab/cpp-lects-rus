#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using std::condition_variable;
using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::unique_lock;

mutex gmut;
int counter {0};
condition_variable data_cond;

void processing() {
  for (;;) {
    unique_lock<mutex> lk{gmut};
    data_cond.wait(lk);
    // here lock for gmut obtained
    cout << counter << endl;
  }
}

void preparation() {
  for(;;) {
    std::lock_guard<std::mutex> lk{gmut};
    // here lock for gmut obtained
    counter += 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));    
    data_cond.notify_one();
  }
}

int
main() {
  thread t1 {processing};
  thread t2 {preparation};
  t1.detach();
  t2.detach();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
