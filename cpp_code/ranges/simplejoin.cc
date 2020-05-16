#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "myranges.hpp"

int main() {
  auto rngs = ranges::views::repeat_n(ranges::views::iota(0, 3), 3);  
  for (auto v : rngs) {
    ranges::copy(v, ranges::ostream_iterator<int>{std::cout, " "});
    std::cout << std::endl;
  }
  
  auto rng = ranges::views::for_each(rngs,
    [](auto v) { return ranges::yield_from(v); });

  ranges::copy(rng, ranges::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;
}