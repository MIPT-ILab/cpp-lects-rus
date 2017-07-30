#include <iostream>
#include <string>
#include <experimental/string_view>
#include <utility>

using std::cout;
using std::endl;
using std::min;
using std::string;
using std::experimental::string_view;

int
main ()
{
  string str = "   trim me  ";
  string_view vtrim = str;
  auto trimfst = vtrim.find_first_not_of(" ");
  vtrim.remove_prefix(min(trimfst, vtrim.size()));
  cout << 'x' << vtrim << 'x' << endl;
  auto trimlst = vtrim.find_last_not_of(" ");
  vtrim.remove_suffix(vtrim.size() - min(trimlst, vtrim.size()));
  cout << 'x' << vtrim << 'x' << endl;
}

