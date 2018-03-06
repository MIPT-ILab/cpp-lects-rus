#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::hex;
using std::showbase;
using std::vector;

int
main () {
  ifstream f("poluslo.jpg");
  int printrow = 0;
  vector<unsigned char> buf;
  while(f) {
    unsigned char next;
    f >> next;
    buf.push_back(next);
    cout << hex << std::setfill('0') << std::setw(2) << +next;
    printrow += 1;
    if ((printrow % 16) == 0) cout << endl;
    else if ((printrow % 2) == 0) cout << " ";
  }
}