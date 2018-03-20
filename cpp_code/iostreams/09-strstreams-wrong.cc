#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ios;
using std::istringstream;
using std::ostringstream;
using std::string;

int main() {
  string s1, s2, s3, s4;
  istringstream input("Ann-Bob Carl:Debora");
  input >> s1 >> s2 >> s3 >> s4;
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  cout << s4 << endl;
}