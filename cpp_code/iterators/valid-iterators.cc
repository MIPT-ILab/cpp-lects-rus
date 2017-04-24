#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using std::cin;
using std::copy;
using std::cout;
using std::front_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::list;
using std::string;
using std::vector;

int 
main ()
{
  istream_iterator<string> beg(cin), end;
  vector<string> vec (beg, end);
  list<string> lst;
  copy (vec.begin(), vec.end(), front_inserter(lst));
  copy (lst.begin(), lst.end(), ostream_iterator<string>(cout, "\n"));
}

