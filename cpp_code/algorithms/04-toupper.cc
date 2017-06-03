#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <cstring>

using std::transform;

using std::cout;
using std::endl;
using std::string;
using std::toupper;

int
main ()
{
  string s = "hello";

#if defined(SHOWBUG)
  transform (s.begin(), s.end(), s.begin(), toupper);
#endif

  transform (s.begin(), s.end(), s.begin(), 
             static_cast<int (*)(int)>(toupper));
  cout << s << endl;

  s = "world";
  transform (s.begin(), s.end(), s.begin(), 
             [](char c){ return toupper(c); });
  cout << s << endl;
}
