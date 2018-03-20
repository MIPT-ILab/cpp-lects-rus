#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::hex;
using std::ios;
using std::istringstream;
using std::ostringstream;
using std::string;

int
main ()
{
  ostringstream fst;
  int n;
  float f;

  fst << 42.2442;
  string s1 = fst.str();
  istringstream iss(s1);
  iss >> n >> f;
  string s2("value: ");
  ostringstream snd (s2, ios::out|ios::ate);
  snd << hex << n << " " << f;
  cout << snd.str() << endl;
}

