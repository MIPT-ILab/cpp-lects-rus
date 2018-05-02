#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::less_equal;
using std::set;

int
main () {
  set<int, less_equal<int>> s = {67, 42, 141, 23, 42, 106, 15, 50};

  for (auto elt : s)
    cout << elt << endl;

  auto itb = s.lower_bound(30);
  auto ite = s.upper_bound(100);
  cout << "lower of 30: " << *itb << endl;
  cout << "upper of 100: " << *ite << endl;

  for (auto it = itb; it != ite; ++it)
    cout << *it << endl;
}


