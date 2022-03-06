#include <algorithm>
#include <cassert>
#include <functional>
#include <future>
#include <numeric>
#ifdef TRYPAR
#include <experimental/numeric>
#endif
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

using std::accumulate;
using std::cout;
using std::endl;
using std::future;
using std::packaged_task;
using std::thread;
using std::vector;

unsigned determine_threads(unsigned length) {
  const unsigned long min_per_thread = 25;
  unsigned long max_threads = length / min_per_thread;
  unsigned long hardware_conc = std::thread::hardware_concurrency();
  //  cout << "max required: " << max_threads << endl;
  //  cout << "hw concurrency: " << hardware_conc << endl;
  return std::min(hardware_conc != 0 ? hardware_conc : 2, max_threads);
}

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
  long length = distance(first, last);
  if (0 == length)
    return init;
  const unsigned nthreads = determine_threads(length);
  long bsize = length / nthreads;

  vector<future<T>> results(nthreads);

  auto accumulate_block = [](Iterator first, Iterator last) {
    return accumulate(first, last, T{});
  };

  unsigned tidx = 0;

  for (; length >= bsize * (tidx + 1); first += bsize, tidx += 1) {
    packaged_task<T(Iterator, Iterator)> task{accumulate_block};
    results[tidx] = task.get_future();
    thread t{move(task), first, first + bsize};
    t.detach();
  }

  auto remainder = length - bsize * tidx;

  T result = init;

  if (remainder > 0) {
    assert(tidx < nthreads);
    result += accumulate_block(first, first + remainder);
  }

  for (unsigned long i = 0; i < nthreads; ++i)
    result += results[i].get();

  return result;
}

template <typename TimeT = std::chrono::microseconds> struct measure {
  template <typename F, typename... Args>
  static typename TimeT::rep execution(F func, Args &&... args) {
    using namespace std::chrono;
    auto start = system_clock::now();
    func(std::forward<Args>(args)...);
    auto duration = duration_cast<TimeT>(system_clock::now() - start);
    return duration.count();
  }
};

int main() {
  constexpr unsigned COUNT = 200000000;
  std::vector<unsigned> v(COUNT);

  // randomising vector contents
  std::mt19937 mersenne_engine;
  std::uniform_int_distribution<unsigned> dist(1, 10);
  auto gen = std::bind(dist, mersenne_engine);
  std::generate(v.begin(), v.end(), gen);

  unsigned sacc, spred, spar;
  cout << "starting ... " << '\n';

  cout << "std::accumulate\t" << measure<>::execution([&] {
    sacc = accumulate(v.begin(), v.end(), 0u);
  }) << endl;

#ifdef TRYPAR
  cout << "std::parallel::reduce\t" << measure<>::execution([&] {
    spred = std::experimental::parallel::reduce(
        std::experimental::parallel::par, v.begin(), v.end());
  }) << endl;
#endif

  cout << "parallel\t" << measure<>::execution([&] {
    spar = parallel_accumulate(v.begin(), v.end(), 0u);
  }) << endl;

  cout << sacc << " == " << spar << endl;
}
