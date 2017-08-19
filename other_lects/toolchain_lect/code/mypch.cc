#include "stdafx.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int
main ()
{
  vector<int> v = {2, 3, 5, 7, 11, 13};
  assert(v.size() == 6);
  string s = "First six primes:";
  cout << s;
  for (auto &elt : v)
    cout << " " << elt;
  cout << endl;
}

