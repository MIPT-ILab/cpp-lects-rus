// Classical producer-consumer with fixed buffer

#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

constexpr int BUFSIZE = 100;
constexpr int MAXTASKS = 10000000;

std::vector<int> buffer(BUFSIZE);
int ncur = 0;
int nsolved = 0;
std::mutex mut;
std::condition_variable data_cond_c, data_cond_p;

void producer() {
  for (;;) {
    // critical section
    {
      std::unique_lock<std::mutex> lk{mut};
      data_cond_p.wait(
          lk, [] { return ((ncur != BUFSIZE) || (nsolved > MAXTASKS)); });
      if (nsolved > MAXTASKS)
        break;
      buffer[ncur] = nsolved;
      ncur += 1;
#ifdef SHOW
      std::cout << "+";
#endif
    }
    data_cond_c.notify_one();
  }
  data_cond_c.notify_all();
}

void consumer() {
  for (;;) {
    // critical section
    {
      std::unique_lock<std::mutex> lk{mut};
      data_cond_c.wait(lk,
                       [] { return ((ncur != 0) || (nsolved > MAXTASKS)); });
      nsolved += 1;
      ncur -= 1;
#ifdef SHOW
      std::cout << "-";
#endif
      if (nsolved > MAXTASKS)
        break;
    }
    data_cond_p.notify_one();
  }
  data_cond_p.notify_all();
}

int main() {
  std::thread p{producer};
  std::thread c{consumer};

#ifdef SECOND
  std::thread p2{producer};
  std::thread c2{consumer};
#endif

  p.join();
  c.join();

#ifdef SECOND
  p2.join();
  c2.join();
#endif
  std::cout << " ... done" << std::endl;
}
