#include <iostream>

using std::cout;
using std::endl;
using std::move;

struct cpmv {
  cpmv() {}
  cpmv(const cpmv&) { cout << "copy ctor" << endl; }
  cpmv(cpmv&&) { cout << "move ctor" << endl; }
  cpmv& operator=(const cpmv&) { cout << "copy assign" << endl; return *this; }
  cpmv& operator=(cpmv&&) { cout << "move assign" << endl; return *this; }
};

class X {
  cpmv data_;
public:
  cpmv const& data() const & { return data_; }
  cpmv&& data() && { return move(data_); }
};

int
main () {
  X obj;
  cout << "1" << endl;
  cpmv a = obj.data();
  cout << "2" << endl;
  cpmv b = X().data();
}