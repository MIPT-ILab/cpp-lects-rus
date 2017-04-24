#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int
main ()
{
  vector<int> v {1, 2, 3, 4, 5, 6, 7};
  auto ri = v.rbegin() + 4; 
  auto it = ri.base();
  cout << *ri << " " << *it << endl;
}

