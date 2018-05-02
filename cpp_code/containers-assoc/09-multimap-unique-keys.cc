#include <map>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::make_pair;
using std::multimap;
using std::string;

int main()
{
  multimap<int,string> mm = {{1, "a"}, {1, "b"}, {2, "c"}, {3, "d"}, {3, "e"}};

  for(auto it = mm.begin(), mend = mm.end();
      it != mend;
      it = mm.upper_bound(it->first))
    cout << it->first << endl;
  return 0;
}