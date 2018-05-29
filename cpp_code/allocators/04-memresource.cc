// memory resource example

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <random>

#include "testresource.hpp"

using std::back_inserter;
using std::cout;
using std::endl;
using std::generate_n;
using std::shuffle;

auto mtgen() {
  static std::random_device rd;
  static std::mt19937 g(rd());
  return g;
}

void pmrvec_testresource() {
  test_resource talloc;

  double start = 0.0;
  pmr::vector<double> v1(&talloc);
  generate_n(back_inserter(v1), 100, 
    [start] () mutable { return (start += 1.1); });

  pmr::vector<double> v2(&talloc);
  v2.assign(v1.begin(), v1.end());
  shuffle(v2.begin(), v2.end(), mtgen()); 
  
  cout << "v1[42] = " << v1[42] << " v2[42] = " << v2[42] << endl;
}

int
main ()
{
  cout << "--- pmr::vector + test resource test ---" << endl;
  pmrvec_testresource();
  cout << "---" << endl;
}