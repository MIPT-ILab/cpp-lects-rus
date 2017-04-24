#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>

using std::istringstream;
using std::istream_iterator;
using std::ostream_iterator;
 
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

int main()
{
    istringstream str ("0.1 0.2 0.3 0.4");

    cross_copy (istream_iterator<double>(str),
                istream_iterator<double>(),
                ostream_iterator<double>(std::cout, " "));
}
