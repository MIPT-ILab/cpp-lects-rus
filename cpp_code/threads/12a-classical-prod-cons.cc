// Classical producer-consumer with fixed buffer

#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::condition_variable;
using std::cout;
using std::endl;
using std::lock_guard;
using std::make_unique;
using std::move;
using std::mutex;
using std::queue;
using std::this_thread::sleep_for;
using std::thread;
using std::unique_lock;
using std::unique_ptr;
using std::vector;

constexpr int BUFSIZE = 100;
constexpr int MAXTASKS = 200;

vector<int> buffer(BUFSIZE);
int ncur = 0;
int nsolved = 0;
mutex mut;
condition_variable data_cond_c, data_cond_p;

void producer() {
  for(;;) {
    // critical section
    {
      unique_lock<mutex> lk{mut};
      data_cond_p.wait(lk, []{
        return ((ncur != BUFSIZE) || (nsolved > MAXTASKS));
      });
      if (nsolved > MAXTASKS) break;
      buffer[ncur] = nsolved;
      ncur += 1;
#ifdef SHOW
      cout << "+";
#endif
    }
    data_cond_c.notify_one();
  }
  data_cond_c.notify_all();
}

void consumer() {
  for(;;) {
    // critical section
    {
      unique_lock<mutex> lk{mut};
      data_cond_c.wait(lk, []{
        return ((ncur != 0) || (nsolved > MAXTASKS));
      });
      nsolved += 1;
      ncur -= 1;
#ifdef SHOW
      cout << "-";
#endif
      if (nsolved > MAXTASKS) break;
    }
    data_cond_p.notify_one();
  }
  data_cond_p.notify_all();
}

int main() {
  thread p{producer}; 
  thread c{consumer};

#ifdef SECOND
  thread p2{producer};
  thread c2{consumer};
#endif
  
  p.join();
  c.join(); 

#ifdef SECOND
  p2.join();
  c2.join();
#endif
  cout << " ... done" << endl;
}
