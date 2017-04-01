#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::istringstream;

int
main ()
{
  ifstream q("quizz.inp");
  string s;

  while (q) {
    q >> s;
    istringstream is (s);
    int i;
    if (is >> i)
      cout << i << endl;
  }
 
}

