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


int foo (Heavy& h) { h.use("foo"); return 0; }
int bar (Heavy&& h) { h.use("bar"); return 0; }

template <typename F, typename T> 
decltype(auto) transparent (F f, T&& x) {
  return f(forward<T>(x));
};

template <typename F, typename T> 
decltype(auto) transparent2 (F f, T&& x) {
  return f(forward<T&&>(x));
};



int
main ()
{
  Heavy h1;
  transparent (foo, h1);
  transparent (bar, move(h1));
  Heavy h2;
  transparent2 (foo, h2);
  transparent2 (bar, move(h2));

  auto transparent3 = [](auto f, auto&& param) { 
    return f(std::forward<decltype(param)>(param));
  };
  Heavy h3;
  transparent3 (foo, h3);
  transparent3 (bar, move(h3));
}

