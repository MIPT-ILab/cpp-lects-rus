#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

template <typename InpIter, typename OutIter>
OutIter cross_copy (InpIter fst, InpIter lst, OutIter dst)
{
  while (fst != lst) {
    *dst = *fst;
    ++fst;
    ++dst;
  }
  return dst;
}

int
main ()
{
  list<int> l1 = {1, 2, 3, 4, 5, 6};
  vector<int> v1;

  v1.resize(l1.size());
  cross_copy (l1.begin(), l1.end(), v1.begin());

  for (auto elt : v1)
    cout << elt << "\n";

  vector<int> v2;
  cross_copy (l1.begin(), l1.end(), back_inserter(v2));
  cross_copy (v2.begin(), v2.end(), std::ostream_iterator<int> (cout, "\n"));  
}


