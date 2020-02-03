//------------------------------------------------------------------------------
//
// Sort benchmark: parallel sort versus regular
//
//------------------------------------------------------------------------------
//
// This file is licensed after GNU GPL v3
//
//------------------------------------------------------------------------------

#include <algorithm>
#include <atomic>
#include <chrono>
#include <execution>
#include <iostream>
#include <random>
#include <string>

using std::chrono::duration_cast;
using chrc = std::chrono::high_resolution_clock;
using cms = std::chrono::milliseconds;

struct config_t {
  int policy;
  int num;
  int ncycles;
  void dump(std::ostream &os) const {
    os << policy << " " << num << " " << ncycles;
  }
};

std::ostream &operator<<(std::ostream &os, const config_t &cfg) {
  cfg.dump(os);
  return os;
}

void print_usage(const char *pname) {
  std::cout << "Usage: '" << pname << " <POLICY> <NUM> <NREP = 1>'\n";
  std::cout << "\twhere policy is 0 for seq, 1 for par, 2 for par_unseq\n";
  std::cout << "\t      num is number of elements to sort (less then 2^31)\n";
  std::cout << "\t      nrep is number of cycles to repeat (less then 2^31)\n";
}

config_t read_config(int argc, char **argv) {
  config_t cfg;
  if ((argc < 3) || (argc > 4)) {
    print_usage(argv[0]);
    exit(0);
  }

  cfg.policy = std::stoi(argv[1]);
  cfg.num = std::stoi(argv[2]);
  cfg.ncycles = 1;
  if (argc > 3)
    cfg.ncycles = std::stoi(argv[3]);

  if ((cfg.policy < 0) || (cfg.policy > 2) || (cfg.num < 1) ||
      (cfg.ncycles < 1)) {
    print_usage(argv[0]);
    exit(0);
  }

#if DEBUG
  std::cout << "Config: " << cfg << std::endl;
#endif
  return cfg;
}

template <typename It> void random_fill(It start, It fin) {
  using VT = typename std::iterator_traits<It>::value_type;
  static std::random_device rnd_device;
  static std::mt19937 mersenne_engine{rnd_device()};
  static std::uniform_int_distribution<VT> dist;
  static auto gen = [] { return dist(mersenne_engine); };
  generate(start, fin, gen);
}

template <typename It> void dump_range(It start, It fin) {
  for (auto it = start; it != fin; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

template <typename T, typename It> void do_bench(T policy, It start, It fin) {
  std::atomic_thread_fence(std::memory_order_seq_cst);
  std::sort(policy, start, fin);
}

int main(int argc, char **argv) {
  auto cfg = read_config(argc, argv);
  std::vector<int> v(cfg.num);
  random_fill(v.begin(), v.end());

#if DEBUG
  dump_range(v.begin(), v.end());
#endif

  auto tstart = chrc::now();
  switch (cfg.policy) {
  case 0:
    for (int i = 0; i < cfg.ncycles; ++i)
      do_bench(std::execution::seq, v.begin(), v.end());
    break;
  case 1:
    for (int i = 0; i < cfg.ncycles; ++i)
      do_bench(std::execution::par, v.begin(), v.end());
    break;
  case 2:
    for (int i = 0; i < cfg.ncycles; ++i)
      do_bench(std::execution::par_unseq, v.begin(), v.end());
    break;
  default:
    std::cerr << "Incorrect policy value" << std::endl;
    exit(0);
  }
  auto tfin = chrc::now();
  std::cout << "Wall time: " << duration_cast<cms>(tfin - tstart).count()
            << std::endl;
}
