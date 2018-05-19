// memory resource example
// C:\Users\kvladimi\Downloads\MinGW\bin\g++ -Wfatal-errors --std=c++17  04-memresource.cc -I "C:\Users\kvladimi\Downloads\MinGW\include" -L "C:\Users\kvladimi\Downloads\MinGW\lib" -lboost_container

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <random>

#include "boost/container/pmr/memory_resource.hpp"
#include "boost/container/pmr/monotonic_buffer_resource.hpp"
#include "boost/container/pmr/polymorphic_allocator.hpp"

using std::back_inserter;
using std::cout;
using std::endl;
using std::generate_n;
using std::shuffle;

using boost::container::pmr::monotonic_buffer_resource;
using boost::container::pmr::polymorphic_allocator;

template <typename T>
using std_vector = std::vector<T>;

template <typename T>
using pmr_vector = std::vector<T, polymorphic_allocator<T>>;

auto mtgen() {
  static std::random_device rd;
  static std::mt19937 g(rd());
  return g;
}

void * operator new (decltype(sizeof(0)) n) noexcept(false) {
  cout << "allocating " << n << endl;
  return malloc(n);
}

void operator delete(void *p) noexcept {
  free(p);
}

void stdvec_test() {
  double start = 0.0;
  std_vector<double> v1;
  generate_n(back_inserter(v1), 100, 
    [start] () mutable { return (start += 1.1); });

  std_vector<double> v2;
  v2.assign(v1.begin(), v1.end());
  shuffle(v2.begin(), v2.end(), mtgen()); 
  
  cout << "v1[42] = " << v1[42] << " v2[42] = " << v2[42] << endl;
}

void pmrvec_test() {
  constexpr size_t sz = 1000 * sizeof(double);
  char buffer[sz] alignas(double);

  monotonic_buffer_resource alloc(buffer, sz);

  double start = 0.0;
  pmr_vector<double> v1(&alloc);
  generate_n(back_inserter(v1), 100, 
    [start] () mutable { return (start += 1.1); });

  pmr_vector<double> v2(&alloc);
  v2.assign(v1.begin(), v1.end());
  shuffle(v2.begin(), v2.end(), mtgen()); 
  
  cout << "v1[42] = " << v1[42] << " v2[42] = " << v2[42] << endl;
}

int
main ()
{
  cout << "--- std::vector test ---" << endl;
  stdvec_test();
  cout << "--- pmr::vector test ---" << endl;
  pmrvec_test();
  cout << "---" << endl;
}