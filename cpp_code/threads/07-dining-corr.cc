// dining philosophers and deadlock avoidnance

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using std::cout;
using std::endl;
using std::lock_guard;
using std::mutex;
using std::thread;
using std::vector;

mutex mstdout;

constexpr int numdiners = 6;
constexpr int NPORTIONS = 10;
constexpr int EATTIME = 10;
constexpr int THINKTIME = 10;
constexpr int TAKETIME = 10;

void mylock(mutex &left, mutex &right) {
  for (;;) {
    left.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(TAKETIME));
    if (right.try_lock())
      break;
    left.unlock();
    std::this_thread::yield();
  }
}

class Philosopher {
  int num_;
  mutex &left_, &right_;

public:
  Philosopher(int num, mutex &left, mutex &right) : 
    num_(num), left_(left), right_(right) {
  }

  void msgout() const {  
    lock_guard<mutex> lk{mstdout};
    cout << num_ << " eating" << endl;
  }

  void eat() {
    // take forks from left and right
    mylock(left_, right_);

    // at this point forks are taken
    msgout();    
    std::this_thread::sleep_for(std::chrono::milliseconds(EATTIME));
    left_.unlock();
    right_.unlock();
  }

  void dine() {
    for (int i = 1; i < NPORTIONS; ++i) {
      eat();
      std::this_thread::sleep_for(std::chrono::milliseconds(THINKTIME));
    }
  }
};

int
main () {
  vector<mutex> forks(numdiners);
  vector<Philosopher> diners;
  for (int i = 0; i < numdiners; ++i) {
    int j = (i == (numdiners - 1)) ? 0 : i + 1;
    diners.emplace_back(i + 1, forks[i], forks[j]);
  }

  vector<thread> threads(numdiners);
  for (int i = 0; i < numdiners; ++i) {
    threads[i] = thread(&Philosopher::dine, diners[i]);
  }
  for (auto& t : threads)
    t.join();
}