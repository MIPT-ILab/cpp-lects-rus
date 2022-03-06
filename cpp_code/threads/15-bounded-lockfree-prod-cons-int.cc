#include <atomic>
#include <cassert>
#include <iostream>
#include <memory>
#include <queue>
#include <thread>
#include <utility>
#include <vector>

using std::atomic;
using std::cout;
using std::endl;
using std::make_unique;
using std::memory_order_acquire;
using std::memory_order_relaxed;
using std::memory_order_release;
using std::move;
using std::thread;
using std::unique_ptr;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::this_thread::sleep_for;

// http://www.1024cores.net/home/lock-free-algorithms/queues/bounded-mpmc-queue
template <typename T> class mpmc_bounded_queue {
  struct cell_t {
    atomic<size_t> sequence_;
    T data_;
  };

  alignas(64) cell_t *const buffer_;
  alignas(64) size_t const buffer_mask_;
  alignas(64) atomic<size_t> enqueue_pos_;
  alignas(64) atomic<size_t> dequeue_pos_;

public:
  mpmc_bounded_queue(size_t bufsize)
      : buffer_(new cell_t[bufsize]), buffer_mask_(bufsize - 1) {

    // assume buffer is 2-aligned
    assert((bufsize >= 2) && ((bufsize & (bufsize - 1)) == 0));
    reinit();
  }

  ~mpmc_bounded_queue() { delete[] buffer_; }

  void reinit() {
    size_t bufsize = buffer_mask_ + 1;
    // fill sequence
    for (size_t i = 0; i != bufsize; ++i)
      buffer_[i].sequence_.store(i, memory_order_relaxed);

    // start enqueue and dequeue with 0
    enqueue_pos_.store(0, memory_order_relaxed);
    dequeue_pos_.store(0, memory_order_relaxed);
  }

  // we assume that push might not be sucessfull
  bool push(T data) {
    cell_t *cell;
    size_t pos;
    bool res = false;

    // CAS loop
    while (!res) {
      pos = enqueue_pos_.load(memory_order_relaxed);

      // using (p & bufmask) instead of (p % bufsize)
      cell = &buffer_[pos & buffer_mask_];
      auto seq = cell->sequence_.load(memory_order_acquire);
      intptr_t diff = intptr_t(seq) - intptr_t(pos);

      // oops, queue moved indeterminately forward
      if (diff < 0)
        return false;

      // if we are guessed enqueue_pos_ => we are done
      if (diff == 0)
        res = enqueue_pos_.compare_exchange_weak(pos, pos + 1,
                                                 memory_order_relaxed);
    }

    cell->data_ = move(data);
    cell->sequence_.store(pos + 1, memory_order_release);
    return true;
  }

  // we assume pop to may fail too
  bool pop(T *data) {
    cell_t *cell;
    size_t pos;
    bool res = false;
    assert(data);

    // CAS loop
    while (!res) {
      pos = dequeue_pos_.load(memory_order_relaxed);
      cell = &buffer_[pos & buffer_mask_];
      auto seq = cell->sequence_.load(memory_order_acquire);
      intptr_t diff = intptr_t(seq) - intptr_t(pos + 1);

      // the same unlucky case
      if (diff < 0)
        return false;

      // if we are guessed dequeue_pos_ => we are done
      if (diff == 0)
        res = dequeue_pos_.compare_exchange_weak(pos, pos + 1,
                                                 memory_order_relaxed);
    }

    *data = move(cell->data_);
    cell->sequence_.store(pos + buffer_mask_ + 1, memory_order_release);
    return true;
  }
};

mpmc_bounded_queue<int> q(128);

// producer: assigns tasks
void producer(int ntasks, int task_producing_msec) {
  for (int i = 0; i < ntasks; ++i) {
    bool succ = false;
    while (!succ) {
      auto task = i;
      succ = q.push(task);
    }
    sleep_for(milliseconds(task_producing_msec));
  }

  // nullptr task to notify consumers to shutdown
  q.push(-1);
}

// consumer: performing tasks
void consumer(int num, int task_consuming_msec) {
  int my_task = -1;
  for (;;) {
    bool succ = q.pop(&my_task);
    if (!succ)
      continue;

    if (my_task == -1) {
      q.push(-1);
      break;
    }

    sleep_for(milliseconds(task_consuming_msec));
  }
}

// playground def-config
constexpr int NTASKS = 100;
constexpr int TASK_PRODUCING_MSEC = 10;
constexpr int TASK_CONSUMING_MSEC = 100;
constexpr int NTHR_START = 2;
constexpr int NTHR_FIN = 20;

int main(int argc, char **argv) {
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

    thread p{[ntasks, task_producing_msec] {
      producer(ntasks, task_producing_msec);
    }};

    vector<thread> vc;
    for (int i = 0; i < nthr; ++i) {
      vc.emplace_back(
          [i, task_consuming_msec] { consumer(i, task_consuming_msec); });
    }

    p.join();
    for (int i = 0; i < nthr; ++i)
      vc[i].join();

    auto tfin = high_resolution_clock::now();

    q.reinit();

    cout << nthr << " " << duration_cast<milliseconds>(tfin - tstart).count()
         << endl;
  }
}