#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include <boost/type_index.hpp>
namespace ti = boost::typeindex;

#include "myranges.hpp"

std::vector<int> foo(int n) {
  std::vector<int> ret(n);
  std::iota(ret.begin(), ret.end(), 0);
  return ret;
}

int main() {
  auto v = foo(42);
  auto res1 = ranges::find(v, 21);
  std::cout << ti::type_id_with_cvr<decltype(res1)>().pretty_name()
            << std::endl;
  std::cout << *res1 << std::endl;

  auto res2 = ranges::find(foo(42), 21);
  std::cout << ti::type_id_with_cvr<decltype(res2)>().pretty_name()
            << std::endl;
#ifdef TRYUB
  std::cout << *res2 << std::endl;
#endif
};