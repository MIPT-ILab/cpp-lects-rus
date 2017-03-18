#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::forward;
using std::move;

struct Heavy
{
  Heavy() { cout << "Heavy ctor" << endl; }
  Heavy(const Heavy&) { cout << "Heavy copied" << endl; }
  Heavy(Heavy&&) { cout << "Heavy moved" << endl; }
  Heavy& operator= (const Heavy&) { cout << "Heavy assigned" << endl; return *this; }
  Heavy& operator= (Heavy&&) { cout << "Heavy move-assigned" << endl; return *this; }
  void use(const char *where) { cout << "Heavy used at " << where << endl; }
};


int foo (Heavy& h, int x) { h.use("foo"); return 0; }
int bar (Heavy&& h, double d, int s) { h.use("bar"); return 0; }

int
main ()
{
  auto transparent = [](auto f, auto&&... param) { 
    return f(std::forward<decltype(param)>(param)...);
  };
  Heavy h;
  transparent (foo, h, 1);
  transparent (bar, move(h), 1.0, 1);
}

