#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "myranges.hpp"

int main() {
  std::vector v = {0, 1, 2, 3, 4, 5, 6};
  ranges::any_view<int> av = v | ranges::view::reverse;
  ranges::copy(av, ranges::ostream_iterator<int>{std::cout, " "});
  std::cout << std::endl;
}