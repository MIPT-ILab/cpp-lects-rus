#include <fstream>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <sstream>
#include <thread>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T> class fire_once;

template <typename R, typename... Args> class fire_once<R(Args...)> {
  std::unique_ptr<void, void (*)(void *)> ptr{nullptr, +[](void *) {}};
  R (*invoke)(void *, Args...) = nullptr;

public:
  fire_once() = default;
  fire_once(fire_once &&) = default;
  fire_once &operator=(fire_once &&) = default;

  template <typename F> fire_once(F &&f) {
    auto pf = std::make_unique<F>(std::move(f));
    invoke = +[](void *pf, Args... args) -> R {
      F *f = reinterpret_cast<F *>(pf);
      return (*f)(std::forward<Args>(args)...);
    };
    ptr = {pf.release(), [](void *pf) {
             F *f = reinterpret_cast<F *>(pf);
             delete f;
           }};
  }

  R operator()(Args &&... args) && {
    R ret = invoke(ptr.get(), std::forward<Args>(args)...);    
    clear();
    return std::move(ret);
  }

  void clear() {
    invoke = nullptr;
    ptr.reset();
  }

  explicit operator bool() const { return static_cast<bool>(ptr); }
};

// generic (type-erased) task to put on queue
// returns -1 if it is special signalling task (end of work for consumers)
// otherwise do what it shall and return 0
using task_t = fire_once<int()>;

template <typename F, typename... Args>
auto create_task(F f, Args &&... args) {
  std::packaged_task<std::remove_pointer_t<F>> tsk{f};
  auto fut = tsk.get_future();
  task_t t{[ct = std::move(tsk),
            args = std::make_tuple(std::forward<Args>(args)...)]() mutable {
    std::apply([ct = std::move(ct)](auto &&... args) mutable { ct(args...); },
               std::move(args));
    return 0;
  }};

  return std::make_pair(std::move(t), std::move(fut));
}

std::queue<task_t> task_queue;
std::mutex task_queue_mutex;
std::mutex cout_mutex;

void safe_push(task_t &&t) {
  std::lock_guard<std::mutex> lk{task_queue_mutex};
  task_queue.push(std::move(t));
}

task_t safe_pop() {
  std::lock_guard<std::mutex> lk{task_queue_mutex};
  task_t cur = std::move(task_queue.front());
  task_queue.pop();
  return cur;
}

bool safe_empty() {
  std::lock_guard<std::mutex> lk{task_queue_mutex};
  return task_queue.empty();
}

void consumer_thread_func() {
  try {
  for (;;) {
    if (safe_empty()) {
      std::this_thread::yield();
      continue;
    }
    task_t cur = safe_pop();
    int res = std::move(cur)();
    if (res == -1) {
      task_t sentinel{[] { return -1; }};
      safe_push(std::move(sentinel));
      break;
    }
  }
  }
  catch(std::exception& e) {
    std::cout << "\n" << e.what() << "\n";
    std::terminate();
  }
  catch(...) {
    std::cout << "\nSomething wrong in thread function\n";
    std::terminate();
  }  
}

int fn1(int x, int y, int z) { std::lock_guard<std::mutex> lk{cout_mutex}; std::cout << "a"; return x + y + z; }

double fn2(std::vector<int> v) { std::lock_guard<std::mutex> lk{cout_mutex}; std::cout << "b"; return v.size() + 0.5; }

void fn3() { std::lock_guard<std::mutex> lk{cout_mutex}; std::cout << "c";}

void test_queue(int ntasks) {
  std::future<int> first_future;
  std::future<double> second_future;  

  for (int jdx = 0; jdx < ntasks; ++jdx) {
    switch (jdx % 3) {
    case 0: {
      auto &&[t, f] = create_task(fn1, 1, 2, 3);      
      safe_push(std::move(t));
      first_future = std::move(f);
      break;
    }
    case 1: {
      std::vector v{1, 2, 3};
      auto &&[t, f] = create_task(fn2, v);
      safe_push(std::move(t));
      second_future = std::move(f);
      break;
    }
    case 2: {
      auto &&[t, f] = create_task(fn3);
      #if defined(IMPLY_ORDER)
      first_future.get();
      second_future.get();
      #endif      
      safe_push(std::move(t));
      break;
    }
    }
  }

  // put final task
  task_t sentinel{[] { return -1; }};
  safe_push(std::move(sentinel));
}

void myhandler() {
  std::cout << "\nterminate happened\n";
  abort();
}

int main() {
  int nthreads = 3;
  int ntasks = 20;
  
  std::set_terminate(myhandler);
  
  std::vector<std::thread> consumers;
  for (int i = 0; i < nthreads; ++i)
    consumers.emplace_back(consumer_thread_func);

  try {
    test_queue(ntasks);

    for (int i = 0; i < nthreads; ++i)
      consumers[i].join();
  
    std::cout << "\nJoined\n";
    return 0;
  }
  catch(std::exception& e) {
    std::cout << "\n" << e.what() << "\n";
  }
  catch(...) {
    std::cout << "\nSomething wrong\n";
  }

  for (int i = 0; i < nthreads; ++i)
    consumers[i].detach();
}
