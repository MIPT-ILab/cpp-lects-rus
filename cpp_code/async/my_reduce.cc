//------------------------------------------------------------------------------
//
// reduce example: parallel reduce versus normal
//
//------------------------------------------------------------------------------
//
// This file is licensed after GNU GPL v3
//
//------------------------------------------------------------------------------

#include <algorithm>
#include <atomic>
#include <cassert>
#include <execution>
#include <iostream>
#include <random>
#include <string>
#include <thread>

template <typename It,
          typename VT = typename std::iterator_traits<It>::value_type>
void random_fill(It start, It fin, VT lowest = 0, VT highest = 100) {
  static std::random_device rnd_device;
  static std::mt19937 mersenne_engine{rnd_device()};
  static std::uniform_int_distribution<VT> dist{lowest, highest};
  static auto gen = [] { return dist(mersenne_engine); };
  generate(start, fin, gen);
}

template <typename It> void dump_range(It start, It fin) {
  for (auto it = start; it != fin; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

constexpr int MINLEN = 25;

unsigned determine_threads(unsigned length) {
  const unsigned long min_per_thread = MINLEN;
  unsigned long max_threads = length / min_per_thread;
  unsigned long hardware_conc = std::thread::hardware_concurrency();
  return std::min(hardware_conc != 0 ? hardware_conc : 2, max_threads);
}

template <typename Iterator,
          typename T = typename std::iterator_traits<Iterator>::value_type>
T parallel_accumulate(Iterator first, Iterator last, T init = 0) {
  long length = distance(first, last);
  if (0 == length)
    return init;
  if (length <= MINLEN)
    return std::accumulate(first, last, init);

  static unsigned nthreads = determine_threads(length);
  long bsize = length / nthreads;

  std::vector<std::thread> threads(nthreads);
  std::vector<T> results(nthreads + 1);

  auto accumulate_block = [](Iterator first, Iterator last, T &result) {
    result = std::accumulate(first, last, result);
  };

  unsigned tidx = 0;

  for (; length >= bsize * (tidx + 1); first += bsize, tidx += 1)
    threads[tidx] = std::thread(accumulate_block, first, first + bsize,
                                std::ref(results[tidx]));

  auto remainder = length - bsize * tidx;

  if (remainder > 0) {
    assert(tidx == nthreads);
    accumulate_block(first, first + remainder, std::ref(results[tidx]));
  }

  for (auto &&t : threads)
    t.join();

  return std::accumulate(results.begin(), results.end(), init);
}

int main(int argc, char **argv) {
  int n = 10;
  if (argc > 1) {
    n = std::stoi(argv[1]);
    assert(n > 0);
  }

  std::vector<unsigned> v(n);
  random_fill(v.begin(), v.end());

#if DEBUG
  dump_range(v.begin(), v.end());
#endif

  auto val1 = std::reduce(v.begin(), v.end());
  auto val2 = parallel_accumulate(v.begin(), v.end());
  std::cout << "Check: " << val1 << " vs " << val2 << std::endl;
}
