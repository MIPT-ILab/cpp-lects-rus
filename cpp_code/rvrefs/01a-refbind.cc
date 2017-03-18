#include <iostream>

using namespace std;

struct RefBind {
  int& ref;
  RefBind(int&& r) : ref(r) {}
  RefBind const& plus (int x) const 
    { ref += x; return *this; }
  RefBind const& mult (int x) const 
    { ref *= x; return *this; }
  int get() const { return ref; }
};

int main () {
  int x = 1;
  cout << RefBind(1).plus(2).mult(3).get() << endl;
  cout << RefBind(std::move(x)).plus(2).mult(3).get() << endl;
  cout << RefBind(x + 0).plus(2).mult(3).get() << endl;
}

