// https://godbolt.org/z/vwXHme

#include <iostream>
#include <functional>
#include <tuple>
#include <experimental/tuple>
#include <utility>

#include "heavy.hpp"

template <typename ... T>
void print_all(T&& ... args) { 
  (std::cout << ... << std::forward<T>(args)) << std::endl; 
}

int main() {
  auto t = std::make_tuple(1, 2.0, 3);
  std::apply(print_all<int, double, int>, std::move(t));
}