#include <iostream>

using std::cout;
using std::endl;

auto AddEleven = [](int n) constexpr {return n + 11;};
constexpr auto ae = AddEleven(31);
static_assert(ae == 42, "");

int
main () {
  cout << ae << endl;
}