// https://godbolt.org/z/vwXHme

#include <iostream>
#include <functional>
#include <tuple>
#include <experimental/tuple>
#include <utility>

#include "heavy.hpp"

using std::experimental::apply;
using std::cout;
using std::endl;
using std::forward;
using std::make_tuple;
using std::move;

template <typename ... T>
void print_all (T&& ... args) { 
  (cout << ... << forward<T>(args)) << endl; 
}

int
main () {
  auto t = make_tuple(1, 2.0, 3);
  apply(print_all<int, double, int>, move(t));
}