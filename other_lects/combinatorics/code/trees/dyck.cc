//-----------------------------------------------------------------------------
// Undirected weighted tree generator
//-----------------------------------------------------------------------------
// takes N from argv[1] and W from argv[2]
// produces weighted undirected tree of size N to cout
//
// format of tree: standard edge list
// N
// V V W
// ....
// V V W
//
// idea of generation:
// first create balanced braces string (vector of bool used)
// 1 means opening brace, 0 means closing
// next read it using stack to (child -> parent) map representation
//-----------------------------------------------------------------------------
//
// This software is licensed under GPLv3
//
//-----------------------------------------------------------------------------

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

// Knuth, 7.2.1.6.W
std::vector<bool> bitstring(int n) {
  assert((n % 2) == 0);

  int p = n / 2, q = n / 2, m = 1;
  std::vector<bool> res(n);

  while (q != 0) {
    for (;;) {
      int x = rand() % ((q + p) * (q - p + 1));
      assert(q + p == n - m + 1);
      if (x < (q + 1) * (q - p)) {
        q -= 1;
        assert(res[m - 1] == false);
        m += 1;
        break;
      }
      p -= 1;
      res[m - 1] = true;
      m += 1;
    }
  }

  return res;
}

void print_str(const std::vector<bool> &v) {
  for (auto elt : v)
    std::cout << (elt ? 1 : 0);
  std::cout << std::endl;
}

std::map<int, int> make_tree(const std::vector<bool> &v) {
  assert(v.size() > 0);
  assert(v[0] == true);
  std::map<int, int> res;
  std::stack<int> s;

  // we have forest on input so basically we need common top)
  s.push(0);
  int curnode = 1;

  for (auto elt : v) {
    if (elt) {
      s.push(curnode);
      curnode += 1;
    } else {
      int child = s.top();
      s.pop();
      assert(!s.empty());
      int parent = s.top();
      assert(res.find(child) == res.end());
      res[child] = parent;
    }
  }

  s.pop();
  assert(s.empty());

  return res;
}

void print_map(const std::map<int, int> &m, int n, int w) {
  assert(n == m.size());
  std::cout << (n + 1) << std::endl;
  for (auto elt : m) {
    std::cout << elt.second << " " << elt.first << " " << ((rand() % w) + 1)
              << std::endl;
  }
}

constexpr int DEFW = 5;

int print_usage(const char *argv0) {
  std::cout << "Usage: '" << argv0 << " N [W]'" << std::endl;
  std::cout << "Where N is number of tree nodes" << std::endl;
  std::cout << "      W is maximum weight, default is " << DEFW << std::endl;
  std::cout << "note: N shall be > 1, W if specified shall be > 1" << std::endl;
  return 1;
}

struct cfg_t {
  int n, w;
};

cfg_t analyze_args(int argc, char **argv) {
  int w = DEFW;
  if (argc < 2)
    exit(print_usage(argv[0]));
  int n = std::stol(argv[1]);
  if (n < 2)
    exit(print_usage(argv[0]));
  if (argc > 2) {
    w = std::stol(argv[2]);
    if (w < 2)
      exit(print_usage(argv[0]));
  }

  return {n, w};
}

int main(int argc, char **argv) {
  auto cf = analyze_args(argc, argv);
  srand(time(NULL));
  auto v = bitstring(cf.n * 2);
  auto t = make_tree(v);
  assert(t.size() == cf.n);
  print_map(t, cf.n, cf.w);
}
