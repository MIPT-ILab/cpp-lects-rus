// try: 
// > g++-10 -std=c++2a exec-pool-piped.cc -lunifex -pthread

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
  std::cout << std::this_thread::get_id() << std::endl;
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
  ex::scheduler auto sched = pool.get_scheduler();
  constexpr int bigx = 1 << 15;
  constexpr int bigy = 1 << 15;

  std::cout << std::unitbuf;
  std::cout << "Sequential\n";
  std::cout << big_fibmod(10, bigx, bigy) << "\n";
  std::cout << big_fibmod(9, bigx, bigy) << "\n";
  std::cout << big_fibmod(8, bigx, bigy) << std::endl;

  std::cout << "Parallel\n";
  ex::sender auto work = ex::when_all(
    ex::schedule(sched) | ex::then([] { return big_fibmod(10, bigx, bigy); }),
    ex::schedule(sched) | ex::then([] { return big_fibmod(9, bigx, bigy); }),
    ex::schedule(sched) | ex::then([] { return big_fibmod(8, bigx, bigy); })
  );

  auto [a, b, c] = tt::sync_wait(std::move(work)).value();  
  auto unwrap = [](auto x) { return std::get<0>(std::get<0>(x)); };

  std::cout << unwrap(a) << " " << unwrap(b) << " " << unwrap(c) << std::endl;
}
