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

  cout << "---" << endl;

  for (auto elt : v1)
    cout << elt << "\n";

  vector<int> v2;
  cross_copy (l1.begin(), l1.end(), back_inserter(v2));

  cout << "---" << endl;
  cross_copy (v2.begin(), v2.end(), std::ostream_iterator<int> (cout, "\n"));  

  vector<int> v3 = {10, 20, 30, 40, 50, 60};
  list<int> l2 = {1, 2, 3, 4, 5, 6};
  cross_copy (l2.begin(), l2.end(), inserter(v3, v3.begin() + 3));

  cout << "---" << endl;
  cross_copy (v3.begin(), v3.end(), std::ostream_iterator<int> (cout, "\n"));  

}


