#include <algorithm>
#include <cassert>
#include <execution>
#include <functional>
#include <future>
#include <numeric>
#include <iostream>
#include <random>
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
  long length = std::distance(first, last);
  if (0 == length)
    return init;
  const unsigned ntasks = determine_threads(length);
  long bsize = length / ntasks;

  std::vector<std::future<T>> results(ntasks);

  auto accumulate_block = [](Iterator first, Iterator last) {
    return std::accumulate(first, last, T{});
  };

  unsigned tidx = 0;

  for (; length >= bsize * (tidx + 1); first += bsize, tidx += 1)
    results[tidx] = std::async(accumulate_block, first, first + bsize);

  auto remainder = length - bsize * tidx;

  T result = init;

  if (remainder > 0) {
    assert(tidx < ntasks);
    result += accumulate_block(first, first + remainder);
  }

  for (unsigned long i = 0; i < ntasks; ++i)
    result += results[i].get();

  return result;
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
  std::vector<unsigned> v(COUNT);

  // randomising vector contents
  std::mt19937 mersenne_engine;
  std::uniform_int_distribution<unsigned> dist(1, 10);
  auto gen = std::bind(dist, mersenne_engine);
  std::generate(v.begin(), v.end(), gen);

  unsigned sacc = 0, spred = 0, spar = 0;
  std::cout << "starting ... " << '\n';

  std::cout << "std::accumulate\t" << measure<>::execution([&] {
    for (int i = 0; i < REP; ++i)
      sacc += std::accumulate(v.begin(), v.end(), 0u);
  }) << std::endl;

#ifdef TRYPAR
  std::cout << "std::parallel::reduce\t" << measure<>::execution([&] {
    for (int i = 0; i < REP; ++i)
    spred += std::reduce(std::execution::par, v.begin(), v.end());
  }) << std::endl;
#endif

  std::cout << "parallel\t" << measure<>::execution([&] {
    for (int i = 0; i < REP; ++i)
      spar += parallel_accumulate(v.begin(), v.end(), 0u);
  }) << std::endl;

  std::cout << sacc << ", " << spar << ", " << spred << std::endl;
}

