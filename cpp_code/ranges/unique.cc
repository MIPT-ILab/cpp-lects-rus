#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "myranges.hpp"

int main() {
  std::vector<int> vec = {2, 5, 13, 17, 2, 3, 5, 7, 11, 13, 17, 19};
  vec.erase(ranges::unique(ranges::begin(vec), ranges::sort(vec)),
            ranges::end(vec));

  ranges::copy(vec, ranges::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;

  // and now better with actions
  vec = {2, 5, 13, 17, 2, 3, 5, 7, 11, 13, 17, 19};
  vec = std::move(vec) | ranges::action::sort | ranges::action::unique;

  ranges::copy(vec, ranges::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;
}
