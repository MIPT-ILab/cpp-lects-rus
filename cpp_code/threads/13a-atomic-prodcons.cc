#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <utility>
#include <vector>

#include "lock_queue.hpp"

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::cout;
using std::endl;
using std::make_unique;
using std::move;
using std::this_thread::sleep_for;
using std::thread;
using std::unique_ptr;
using std::vector;


lock_queue<unique_ptr<int>> q;

// producer: assigns tasks
void producer(int ntasks, int task_producing_msec) {
  for (int i = 0; i < ntasks; ++i) {
    auto task = make_unique<int>(i);
    sleep_for(milliseconds(task_producing_msec));
    q.push(move(task));
  }
  
#ifdef SHOW
  cout << "produced " << ntasks << endl;
#endif

  // nullptr task to notify consumers to shutdown
  q.push(nullptr);
}

// consumer: performing tasks
void consumer(int num, int task_consuming_msec) {
  unique_ptr<int> my_task = nullptr;
  for(;;) {
    bool exists = q.pop(my_task);
    
    if (exists && (my_task == nullptr)) {
      q.push(nullptr);
      break;
    }

    sleep_for(milliseconds(task_consuming_msec));
#ifdef SHOW
    cout << "consumed " << task_consuming_msec << " spent" << endl;
#endif
  }
}

// playground def-config
constexpr int NTHR = 10;
constexpr int NTASKS = 100;
constexpr int TASK_PRODUCING_MSEC = 10;
constexpr int TASK_CONSUMING_MSEC = 100;

int
main(int argc, char **argv) {
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
  cout << "NTHR = " << nthr << endl;
#endif

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

  cout << duration_cast<milliseconds>(tfin - tstart).count() << endl;
}
