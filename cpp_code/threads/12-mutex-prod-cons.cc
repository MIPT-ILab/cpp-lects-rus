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

queue<unique_ptr<int>> q;
mutex mut;
condition_variable data_cond;

// producer: assigns tasks
void producer(int ntasks, int task_producing_msec) {
  for (int i = 0; i < ntasks; ++i) {
    auto task = make_unique<int>(i);
    sleep_for(milliseconds(task_producing_msec));
    
    // critical section
    {
      lock_guard<mutex> lk{mut};
      q.push(move(task));
    }
    
    data_cond.notify_one();
  }
  
  // nullptr task to notify consumers to shutdown
  {
    lock_guard<mutex> lk{mut};
    q.push(nullptr);
  }
  data_cond.notify_all();
}

// consumer: performing tasks
void consumer(int num, int task_consuming_msec) {
  unique_ptr<int> my_task = nullptr;
  for(;;) {
    // critical section
    {
      unique_lock<mutex> lk{mut};
      data_cond.wait(lk, []{ return !q.empty(); });
      my_task = move(q.front());
      if (my_task == nullptr)
        break;
      q.pop();
    }

    sleep_for(milliseconds(task_consuming_msec));
  }
}

// playground def-config
constexpr int NTASKS = 100;
constexpr int TASK_PRODUCING_MSEC = 10;
constexpr int TASK_CONSUMING_MSEC = 100;
constexpr int NTHR_START = 2;
constexpr int NTHR_FIN = 10;

int
main(int argc, char **argv) {
  auto ntasks = NTASKS;
  auto task_producing_msec = TASK_PRODUCING_MSEC;
  auto task_consuming_msec = TASK_CONSUMING_MSEC;

  if (argc > 1)
    ntasks = std::stoi(argv[1]);

  if (argc > 2)
    task_producing_msec = std::stoi(argv[2]);

  if (argc > 3)
    task_consuming_msec = std::stoi(argv[3]);

  for (int nthr = NTHR_START; nthr < NTHR_FIN; ++nthr) {

    auto tstart = high_resolution_clock::now();

    thread p{[ntasks, task_producing_msec]{ 
      producer(ntasks, task_producing_msec); 
    }};
    
    vector<thread> vc;
    for (int i = 0; i < nthr; ++i) {
      vc.emplace_back([i, task_consuming_msec]{ 
        consumer(i, task_consuming_msec);
      });
    }
    
    p.join();
    for (int i = 0; i < nthr; ++i)
      vc[i].join();

    auto tfin = high_resolution_clock::now();

    queue<unique_ptr<int>>().swap(q);

    cout << nthr << " " << 
            duration_cast<milliseconds>(tfin - tstart).count() << endl;
  }
}