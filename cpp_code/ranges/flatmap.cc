#include <boost/container/flat_map.hpp>
#include <iostream>
#include <string>

#include "myranges.hpp"

namespace container = boost::container;

int main() {
  container::flat_map<std::string, int> fm;
  fm["world"] = 2;
  fm["hello"] = 1;

  for (auto [k, v] : ranges::reverse_view{fm})
    std::cout << k << ": " << v << std::endl;
}
