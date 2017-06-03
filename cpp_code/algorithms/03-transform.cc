#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>

using std::copy;
using std::fill;
using std::for_each;
using std::transform;

using std::cout;
using std::endl;

using std::ostream_iterator;

using std::vector;

int
main ()
{
  vector<int> v = {2, 3, 5, 7, 11, 13};
  for_each(v.begin(), v.end(), [] (auto& i) { i = -i; } );
  copy (v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));

  v = {2, 3, 5, 7, 11, 13};
  transform (v.begin(), v.end(), v.begin(), [] (auto i) { return -i; } );
  copy (v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
  
  v = {2, 3, 5, 7, 11, 13};
  transform (v.begin(), v.end(), v.begin(), std::negate<int>());
  copy (v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
}

