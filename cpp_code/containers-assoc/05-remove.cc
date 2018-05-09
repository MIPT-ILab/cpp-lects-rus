#include <iostream>
#include <set>
#include <algorithm>

using std::cout;
using std::endl;
using std::remove;
using std::set;

int main() {
  set<int> s = {1, 2};
  *s.begin() = 3;
  // s.erase(remove(s.begin(), s.end(), 1), s.end());
  for (auto elt : s)
    cout << elt << endl;
}
