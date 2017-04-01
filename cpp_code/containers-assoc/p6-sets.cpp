#include <set>
#include <iostream>

int
main (void)
{
  std::set<int> s{5, 1, 3, 2, 4};
  auto l = s.lower_bound(3);
  auto u = s.upper_bound(3);
  int prev = *--l;
  int next = *++u;

  std::cout << prev << " " << next << std::endl;
}

