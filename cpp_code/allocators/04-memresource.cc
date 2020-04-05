// memory resource example

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <random>
#include <vector>

#include "testresource.hpp"

using std::back_inserter;
using std::cout;
using std::endl;
using std::generate_n;
using std::shuffle;
using std::pmr::vector;

auto mtgen() {
  static std::random_device rd;
  static std::mt19937 g(rd());
  return g;
}

void pmrvec_testresource() {
  cout << "--- pmr::vector + test resource test ---" << endl;
  test_resource talloc;

  // allocate smth to leak
  (void)talloc.allocate(10, 4);

  double start = 0.0;
  vector<double> v1(&talloc);
  generate_n(back_inserter(v1), 100,
             [start]() mutable { return (start += 1.1); });

  vector<double> v2(&talloc);
  v2.assign(v1.begin(), v1.end());
  shuffle(v2.begin(), v2.end(), mtgen());

  cout << "v1[42] = " << v1[42] << " v2[42] = " << v2[42] << endl;
  cout << "---" << endl;
}

int main() { pmrvec_testresource(); }
