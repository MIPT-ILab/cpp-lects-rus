// try: 
// > g++-10 -std=c++2a exec-pool.cc -lunifex -pthread

#include <iostream>

#include <unifex/execute.hpp>
#include <unifex/then.hpp>
#include <unifex/static_thread_pool.hpp>
#include <unifex/sync_wait.hpp>
#include <unifex/when_all.hpp>

namespace ex = unifex; // std::execution
namespace tt = unifex; // std::this_thread

template <typename T> struct TD;

int big_fibmod(int m, int BIGX, int BIGY) {
  int a = 0, b = 1;
  for (int i = 0; i < BIGX; i++)
    for (int j = 0; j < BIGY; j++) {
      int tmp = (a + b) % m;
      a = b;
      b = tmp;
    }
  return b;
}

int main() {
  unifex::static_thread_pool pool{3};
  auto sched = pool.get_scheduler();

  auto work = ex::when_all(
    ex::then(ex::schedule(sched), [] { return big_fibmod(10, 1 << 15, 1 << 15); }),
    ex::then(ex::schedule(sched), [] { return big_fibmod(9, 1 << 15, 1 << 15); }),
    ex::then(ex::schedule(sched), [] { return big_fibmod(8, 1 << 15, 1 << 15); })
  );

  auto [a, b, c] = tt::sync_wait(std::move(work)).value();  
  auto unwrap = [](auto x) { return std::get<0>(std::get<0>(x)); };

  std::cout << unwrap(a) << " " << unwrap(b) << " " << unwrap(c) << std::endl;
}