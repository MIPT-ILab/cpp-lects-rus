#include <cassert>
#include <string>

using std::string;

int
main ()
{
  string astr = "hello";
  string bstr; 
  bstr.reserve(15);
  int alen = astr.length();
  assert(alen == 5);
  bstr = astr;
  bstr += ", world!";
  int res = astr.compare(bstr);
  assert(res < 0);
}

