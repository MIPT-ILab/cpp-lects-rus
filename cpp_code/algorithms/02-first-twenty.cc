#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using std::copy;
using std::copy_n;
using std::cout;
using std::iota;
using std::sort;
using std::partial_sort;
using std::vector;

int
main ()
{
  vector<int> v(10000);
  iota (v.begin(), v.end(), 0);

  // 1. sort
  random_shuffle (v.begin(), v.end());
  sort (v.begin(), v.end());
  copy_n (v.begin(), 5, std::ostream_iterator<int>(cout, "\n")); 

  // 2. partial_sort 
  random_shuffle (v.begin(), v.end());
  partial_sort (v.begin(), v.begin() + 5, v.end());
  copy_n (v.begin(), 5, std::ostream_iterator<int>(cout, "\n")); 

  // 3. nth_element
  random_shuffle (v.begin(), v.end());
  nth_element (v.begin(), v.begin() + 5, v.end());
  copy_n (v.begin(), 5, std::ostream_iterator<int>(cout, "\n"));  
}

