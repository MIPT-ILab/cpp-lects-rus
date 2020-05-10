#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "myranges.hpp"

int main() {
  auto inflist = ranges::views::ints(1, ranges::unreachable);
  auto tensquares = inflist |
                    ranges::views::transform([](int i) { return i * i; }) |
                    ranges::views::take(10);
#if INFSCREEN
  ranges::copy(inflist, ranges::ostream_iterator<int>{std::cout, " "});
#else
  ranges::copy(tensquares, ranges::ostream_iterator<int>{std::cout, " "});
#endif
  std::cout << std::endl;
}
