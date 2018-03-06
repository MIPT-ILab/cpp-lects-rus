#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::hex;
using std::showbase;
using std::vector;

int
main () {
  ifstream f("poluslo.jpg", ifstream::binary);
  int printrow = 0;
  f.seekg(0, ifstream::end);
  auto sz = f.tellg();
  cout << "Reserving: " << sz << endl;
  vector<unsigned char> buf;
  f.seekg(0, ifstream::beg);
  while(f) {
    unsigned char next;
    f >> std::noskipws >> next;
    buf.push_back(next);
    cout << hex << std::setfill('0') << std::setw(2) << +next;
    printrow += 1;
    if ((printrow % 16) == 0) cout << endl;
    else if ((printrow % 2) == 0) cout << " ";
  }
}