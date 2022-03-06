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
public:
  mpmc_bounded_queue(size_t bufsize)
      : buffer_(new cell_t[bufsize]), buffer_mask_(bufsize - 1) {

    // assume buffer is 2-aligned
    assert((buffer_size >= 2) && ((buffer_size & (buffer_size - 1)) == 0));

    // fill sequence
    for (size_t i = 0; i != buffer_size; i += 1)
      buffer_[i].sequence_.store(i, memory_order_relaxed);

    // start enqueue and dequeue with 0
    enqueue_pos_.store(0, memory_order_relaxed);
    dequeue_pos_.store(0, memory_order_relaxed);
  }

  ~mpmc_bounded_queue() { delete[] buffer_; }

  // we assume that push might not be sucessfull
  bool push(T data) {
    cell_t *cell;
    size_t pos = enqueue_pos_.load(memory_order_relaxed);
    for (;;) {
      cell = &buffer_[pos & buffer_mask_];
      size_t seq = cell->sequence_.load(memory_order_acquire);
      intptr_t dif = (intptr_t)seq - (intptr_t)pos;

      // we are guessed enqueue_pos_ => we are done
      if ((dif == 0) && (enqueue_pos_.compare_exchange_weak(
                            pos, pos + 1, memory_order_relaxed)))
        break;

      if (dif < 0)
        return false;

      pos = enqueue_pos_.load(memory_order_relaxed);
    }

    cell->data_ = move(data);
    cell->sequence_.store(pos + 1, std::memory_order_release);
    return true;
  }

  // assume nothrowing move-ctor
  bool pop(T &&data) {
    cell_t *cell;
    size_t pos = dequeue_pos_.load(std::memory_order_relaxed);

    for (;;) {
      cell = &buffer_[pos & buffer_mask_];
      size_t seq = cell->sequence_.load(std::memory_order_acquire);
      intptr_t dif = (intptr_t)seq - (intptr_t)(pos + 1);
      if ((dif == 0) && (dequeue_pos_.compare_exchange_weak(
                            pos, pos + 1, std::memory_order_relaxed)))
        break;
      else if (dif < 0)
        return false;
      else
        pos = dequeue_pos_.load(std::memory_order_relaxed);
    }

    data = move(cell->data_);
    cell->sequence_.store(pos + buffer_mask_ + 1, std::memory_order_release);

    return true;
  }

private:
  struct cell_t {
    atomic<size_t> sequence_;
    T data_;
  };

  cell_t *const buffer_;
  size_t const buffer_mask_;
  std::atomic<size_t> enqueue_pos_;
  std::atomic<size_t> dequeue_pos_;

  mpmc_bounded_queue(mpmc_bounded_queue const &);
  void operator=(mpmc_bounded_queue const &);
};

mpmc_bounded_queue<unique_ptr<int>> q(128);

// producer: assigns tasks
void producer(int ntasks, int task_producing_msec) {
  for (int i = 0; i < ntasks; ++i) {
    bool succ = false;
    while (!succ) {
      auto task = make_unique<int>(i);
      succ = q.push(move(task));
    }
    sleep_for(milliseconds(task_producing_msec));
  }

  // nullptr task to notify consumers to shutdown
  q.push(nullptr);
}

// consumer: performing tasks
void consumer(int num, int task_consuming_msec) {
  unique_ptr<int> my_task = nullptr;
  for (;;) {
    bool succ = q.pop(move(my_task));
    if (!succ)
      continue;

    if (my_task == nullptr) {
      q.push(nullptr);
      break;
    }

    sleep_for(milliseconds(task_consuming_msec));
  }
}

// playground def-config
constexpr int NTHR = 10;
constexpr int NTASKS = 100;
constexpr int TASK_PRODUCING_MSEC = 10;
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
  cout << "NTHR = " << nthr << endl;
#endif

  auto tstart = high_resolution_clock::now();

  thread p{
      [ntasks, task_producing_msec] { producer(ntasks, task_producing_msec); }};

  vector<thread> vc;
  for (int i = 0; i < nthr; ++i) {
    vc.emplace_back(
        [i, task_consuming_msec] { consumer(i, task_consuming_msec); });
  }

  p.join();
  for (int i = 0; i < nthr; ++i)
    vc[i].join();

  auto tfin = high_resolution_clock::now();

  cout << duration_cast<milliseconds>(tfin - tstart).count() << endl;
}