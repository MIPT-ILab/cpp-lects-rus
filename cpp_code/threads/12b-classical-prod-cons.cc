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
std::condition_variable data_full, data_empty;

void producer() {
  for (;;) {
    // critical section
    std::unique_lock<std::mutex> lk{mut};
    data_full.wait(lk,
                   [] { return ((ncur != BUFSIZE) || (nsolved > MAXTASKS)); });
    if (nsolved > MAXTASKS)
      break;
    buffer[ncur] = nsolved;
    ncur += 1;
#ifdef SHOW
    std::cout << "+";
#endif
    if (ncur == 1)
      data_empty.notify_one();
  }
  data_empty.notify_all();
}

void consumer() {
  for (;;) {
    std::unique_lock<std::mutex> lk{mut};
    data_empty.wait(lk, [] { return ((ncur != 0) || (nsolved > MAXTASKS)); });
    nsolved += 1;
    ncur -= 1;
#ifdef SHOW
    std::cout << "-";
#endif
    if (nsolved > MAXTASKS)
      break;
    if (ncur == BUFSIZE - 1)
      data_full.notify_one();
  }
  data_full.notify_all();
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
