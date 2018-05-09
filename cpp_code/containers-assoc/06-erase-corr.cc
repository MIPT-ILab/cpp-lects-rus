#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

int
main () {
  set<int> s = {67, 42, 141, 23, 42, 106, 15, 50};

  for (auto it = s.begin(); it != s.end();)
    if ((*it < 100) && (*it > 30)) 
      s.erase(it++);
    else
      ++it;

  for (auto elt : s)
    cout << elt << endl;
}


