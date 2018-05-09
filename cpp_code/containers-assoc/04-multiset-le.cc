#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::less;
using std::less_equal;
using std::multiset;

int
main () {
#ifdef CORR
  multiset<int, less<int>> s = {10, 10};
#else
  multiset<int, less_equal<int>> s = {10, 10};
#endif
  auto ret = s.equal_range(10);
  s.erase(ret.first, ret.second);
  for (auto elt : s)
    cout << elt << endl;
}

