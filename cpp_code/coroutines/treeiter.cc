#include <cassert>
#include <chrono>
#include <iostream>
#include <queue>
#include <stack>

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

struct iter_t {
  std::stack<node_t*> stack_;

  explicit iter_t(node_t *p) {
    stack_.push(p);
  }
  
  int *nextpre() {
    if (stack_.empty())
      return nullptr;
    node_t *cur = stack_.top();
    stack_.pop();
    if (cur->lhs_) stack_.push(cur->lhs_);
    if (cur->rhs_) stack_.push(cur->rhs_);
    return &cur->data_;  
  }
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  assert(n > 1);
  assert(m > 1);

  node_t *top = generate(n);

  auto tstart = high_resolution_clock::now();
  for (int i = 0; i < m; ++i) {
    iter_t it(top);
    while(it.nextpre()) {
    }
  }
  auto tfin = high_resolution_clock::now();

  std::cout << duration_cast<milliseconds>(tfin - tstart).count() << std::endl;  
}