#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int
main ()
{
  istream_iterator<string> beg(cin), end; 
  vector<string> vec (beg, end); 
  copy (vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n"));
}

