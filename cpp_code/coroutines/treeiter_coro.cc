#include <cassert>
#include <chrono>
#include <iostream>
#include <queue>
#include <stack>

#include "rec_generator.hpp"

using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;

struct node_t {
  int data_;
  node_t * lhs_ = nullptr, * rhs_ = nullptr;

  explicit node_t(int data = 0) : data_{data} {}
};

node_t * generate(int leafs) {
  node_t *top = new node_t{};
  std::queue<node_t *> nodes;
  nodes.push(top);
  for (int i = 0; i < leafs; ++i) {
    node_t *cur = nodes.front();
    nodes.pop();
    cur->lhs_ = new node_t{i};
    cur->rhs_ = new node_t{i};
    nodes.push(cur->lhs_);
    nodes.push(cur->rhs_);
  }
  return top;
}

rec_generator<int> tree_preorder(node_t *cur) {
  co_yield cur->data_;
  if (cur->lhs_)
    co_yield tree_preorder(cur->lhs_);
  if (cur->rhs_)
    co_yield tree_preorder(cur->rhs_);
}

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  assert(n > 1);
  assert(m > 1);

  node_t *top = generate(n);

  auto tstart = high_resolution_clock::now();
  for (int i = 0; i < m; ++i) {
    auto rgen = tree_preorder(top);
    while(rgen.next()){}
  }
  auto tfin = high_resolution_clock::now();

  std::cout << duration_cast<milliseconds>(tfin - tstart).count() << std::endl;  
}