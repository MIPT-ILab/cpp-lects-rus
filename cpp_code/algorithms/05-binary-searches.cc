#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;

using std::equal_range;
using std::lower_bound;
using std::upper_bound;

int
main ()
{
  vector<int> v = {1, 2, 3, 4, 5, 6, /* 42, 42, 42, */ 91, 92, 93, 94};
  auto itl = lower_bound(v.begin(), v.end(), 42);
  auto itu = upper_bound(v.begin(), v.end(), 42);
  auto itp = equal_range(v.begin(), v.end(), 42);
  cout << *itl << " " << *itu << endl;
  cout << *itp.first << " " << *itp.second << endl;
}

