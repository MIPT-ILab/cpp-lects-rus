#include <algorithm>
#include <locale>
#include <string>
#include <iostream>
#include <sstream>

using std::ctype;
using std::copy_n;
using std::cout;
using std::endl;
using std::ios;
using std::istringstream;
using std::locale;
using std::ostringstream;
using std::string;

class my_ctype : public ctype<char> {
  mask my_table[table_size]; 
public:
  my_ctype(size_t refs = 0) : ctype<char>(&my_table[0], false, refs) {
    copy_n(classic_table(), table_size, my_table);
    my_table['-'] = (mask)space;
    my_table[':'] = (mask)space;
  }
};

int main() {
  string s1, s2, s3, s4;
  istringstream input("Ann-Bob Carl:Debora");
  locale x(locale::classic(), new my_ctype);
  input.imbue(x);
  input >> s1 >> s2 >> s3 >> s4;
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  cout << s4 << endl;
}
