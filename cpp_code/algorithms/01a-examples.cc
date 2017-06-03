#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::copy;
using std::copy_n;
using std::copy_if;

using std::cout;
using std::endl;

using std::ostream_iterator;

using std::vector;

int
main ()
{
  int myints[] = {2, 3, 5, 7, 11, 13, 17}; 
  vector<int> myvector (7);

  copy_n (myints, 7, myvector.begin());
  copy (myvector.begin(), myvector.end(), ostream_iterator<int>(cout, "\n"));

  fill (myvector.begin(), myvector.end(), 0);
  copy_if (myints, myints+7, myvector.begin(), [](int i){ return (i % 3) == 1; });
  copy (myvector.begin(), myvector.end(), ostream_iterator<int>(cout, "\n"));
}

