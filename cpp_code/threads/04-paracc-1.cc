#include <algorithm>
#include <cassert>
#include <execution>
#include <numeric>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>

namespace chr = std::chrono;

unsigned determine_threads(unsigned length) {
  const unsigned long min_per_thread = 25;
  unsigned long max_threads = length / min_per_thread;
  unsigned long hardware_conc = std::thread::hardware_concurrency();
#if 0
  std::cout << "max required: " << max_threads << std::endl;
  std::cout << "hw concurrency: " << hardware_conc << std::endl;
#endif
  return std::min(hardware_conc != 0 ? hardware_conc : 2, max_threads);
}

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
  long length = distance(first, last);
  if (0 == length)
    return init;
  unsigned nthreads = determine_threads(length);
  long bsize = length / nthreads;

  std::vector<std::thread> threads(nthreads);
  std::vector<T> results(nthreads + 1);

  auto accumulate_block = [](Iterator first, Iterator last, T &result) {
    result = std::accumulate(first, last, result);
  };

  unsigned tidx = 0;

  for (; length >= bsize * (tidx + 1); first += bsize, tidx += 1)
    threads[tidx] =
        std::thread(accumulate_block, first, first + bsize, std::ref(results[tidx]));

  auto remainder = length - bsize * tidx;

  if (remainder > 0) {
    assert(tidx == nthreads);
    accumulate_block(first, first + remainder, std::ref(results[tidx]));
  }

  for (auto &&t : threads)
    t.join();

  return std::accumulate(results.begin(), results.end(), init);
}

template <typename TimeT = std::chrono::microseconds> struct measure {
  template <typename F, typename... Args>
  static typename TimeT::rep execution(F func, Args &&... args) {
    auto start = chr::system_clock::now();
    func(std::forward<Args>(args)...);
    auto duration = chr::duration_cast<TimeT>(chr::system_clock::now() - start);
    return duration.count();
  }
};

int main() {
  constexpr unsigned COUNT = 200000;
  constexpr unsigned REP = 1000;
  unsigned sacc = 0, spred = 0, spar = 0;
  std::vector<unsigned> v(COUNT);
  std::iota(v.begin(), v.end(), 0);  
  std::cout << "starting ... " << '\n';

  std::cout << "std::accumulate\t" << measure<>::execution([&] {
    for (int i = 0; i < REP; ++i)
      sacc += std::accumulate(v.begin(), v.end(), 0u);
  }) << std::endl;

  std::cout << "parallel\t" << measure<>::execution([&] {
    for (int i = 0; i < REP; ++i)
      spar += parallel_accumulate(v.begin(), v.end(), 0u);
  }) << std::endl;

  if (sacc != spar)
    std::cout << sacc << " != " << spar << std::endl;

#ifdef TRYPAR
  std::cout << "std::parallel::reduce\t" << measure<>::execution([&] {
    for (int i = 0; i < REP; ++i)
    spred += std::reduce(std::execution::par, v.begin(), v.end());
  }) << std::endl;

  if (sacc != spred)
    std::cout << sacc << " != " << spred << std::endl;
#endif
}