#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "myranges.hpp"

int main() {
  auto is_odd = [](auto x) { return (x % 2) != 0; };

  auto inflist = ranges::views::ints(1, ranges::unreachable);
  auto odds = inflist | ranges::views::filter(is_odd) | ranges::views::take(10);
  ranges::copy(odds, ranges::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;

  auto modulo_six = [](auto x) { return ((x % 6) == 1) || ((x % 6) == 5); };
  auto first_approx = ranges::views::concat(
      ranges::views::single(2), ranges::views::single(3),
      inflist | ranges::views::drop(4) | ranges::views::filter(modulo_six));

  ranges::copy(first_approx | ranges::views::take(10),
               ranges::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;
}
