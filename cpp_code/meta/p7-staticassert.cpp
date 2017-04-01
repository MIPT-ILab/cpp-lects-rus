#include <utility>

using namespace std;

auto main() -> int
{
  typedef integral_constant<int, 3> two_t;
  typedef integral_constant<int, 4> four_t;
  static_assert (two_t::value * two_t::value == four_t::value, "2*2 != 4");

  return 0;
}

