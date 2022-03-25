#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

namespace chr = std::chrono;
namespace tth = std::this_thread;

std::queue<std::unique_ptr<int>> q;
std::mutex mut;
std::condition_variable data_cond;

// producer: assigns tasks
void producer(int ntasks, int task_producing_msec) {
  for (int i = 0; i < ntasks; ++i) {
    auto task = std::make_unique<int>(i);
    tth::sleep_for(chr::milliseconds(task_producing_msec));

    // critical section
    {
      std::lock_guard<std::mutex> lk{mut};
      q.push(move(task));
    }

    data_cond.notify_one();
  }

#ifdef SHOW
  std::cout << "produced " << ntasks << std::endl;
#endif

  // nullptr task to notify consumers to shutdown
  {
    std::lock_guard<std::mutex> lk{mut};
    q.push(nullptr);
  }
  data_cond.notify_all();
}

// consumer: performing tasks
void consumer(int num, int task_consuming_msec) {
  std::unique_ptr<int> my_task = nullptr;
  for (;;) {
    // critical section
    {
      std::unique_lock<std::mutex> lk{mut};
      data_cond.wait(lk, [] { return !q.empty(); });
      my_task = std::move(q.front());
      if (my_task == nullptr)
        break;
      q.pop();
    }

    tth::sleep_for(chr::milliseconds(task_consuming_msec));
#ifdef SHOW
    std::cout << "consumed " << task_consuming_msec << " spent" << std::endl;
#endif
  }
}

// playground def-config
constexpr int NTHR = 10;
constexpr int NTASKS = 800;
constexpr int TASK_PRODUCING_MSEC = 0;
constexpr int TASK_CONSUMING_MSEC = 100;

int main(int argc, char **argv) {
  auto nthr = NTHR;
  auto ntasks = NTASKS;
  auto task_producing_msec = TASK_PRODUCING_MSEC;
  auto task_consuming_msec = TASK_CONSUMING_MSEC;

  if (argc > 1)
    nthr = std::stoi(argv[1]);

  if (argc > 2)
    ntasks = std::stoi(argv[2]);

  if (argc > 3)
    task_producing_msec = std::stoi(argv[3]);

  if (argc > 4)
    task_consuming_msec = std::stoi(argv[4]);

#ifdef SHOW
  std::cout << "NTHR = " << std::nthr << endl;
#endif

  auto tstart = chr::high_resolution_clock::now();

  std::thread p{
      [ntasks, task_producing_msec] { producer(ntasks, task_producing_msec); }};

  std::vector<std::thread> vc;
  for (int i = 0; i < nthr; ++i) {
    vc.emplace_back(
        [i, task_consuming_msec] { consumer(i, task_consuming_msec); });
  }

  p.join();
  for (int i = 0; i < nthr; ++i)
    vc[i].join();

  auto tfin = chr::high_resolution_clock::now();

  std::queue<std::unique_ptr<int>>().swap(q);

  std::cout << chr::duration_cast<chr::milliseconds>(tfin - tstart).count()
            << std::endl;
}
