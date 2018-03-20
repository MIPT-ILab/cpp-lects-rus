#include <locale>
#include <string>
#include <iostream>
#include <sstream>

using std::ctype;
using std::cout;
using std::endl;
using std::ios_base;
using std::istringstream;
using std::locale;
using std::ostream;
using std::ostringstream;
using std::string;

struct ReversedString {
  static int is_rev;
  string data;
};

int ReversedString::is_rev = ios_base::xalloc();

ios_base& rev(ios_base& os) {
  os.iword (ReversedString::is_rev) = !os.iword (ReversedString::is_rev);
  return os;
}

ostream& operator<<(ostream& os, ReversedString& f) {
  if(os.iword(ReversedString::is_rev) == 1)
    return os << string(f.data.rbegin(), f.data.rend());
  return os << f.data;
}

int
main() {
  ReversedString r {.data = "a roza upala na lapu azora"};
  cout << rev << r << endl;
  cout << r << endl;
  cout << rev << r << endl;
}

