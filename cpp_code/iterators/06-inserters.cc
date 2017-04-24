#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::find;
using std::vector;

int
main ()
{
  vector<int> v = {2, 3, 7, 11};
  auto it = find (v.begin(), v.end(), 3);
  auto insit = inserter (v, it);

  insit = 5;

  std::copy (v.begin(), v.end(), std::ostream_iterator<int>(cout, "\n"));
}

