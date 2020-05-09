#include <boost/type_index.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "myranges.hpp"

using boost::typeindex::type_id_with_cvr;

int main() {
#ifndef BUG
  std::vector<std::string> v{"01", "23", "45"};
#else
  std::vector<int> v{0, 1, 2, 3, 4, 5}; // we can not "join" view of this vector
#endif

  std::cout << type_id_with_cvr<decltype(v)>().pretty_name() << std::endl;

  auto tv = ranges::views::take(v, 2);

  std::cout << type_id_with_cvr<decltype(tv)>().pretty_name() << std::endl;

  auto jv = ranges::views::join(tv);

  std::cout << type_id_with_cvr<decltype(jv)>().pretty_name() << std::endl;

#ifndef NOPRINOUT
  // but bug will not reproduce before this point
  for (auto &&s : jv)
    std::cout << s << " ";
  std::cout << std::endl;
#endif
}
