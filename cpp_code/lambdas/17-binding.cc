#include <iostream>
#include <functional>
#include <utility>

using std::bind;
using std::function;
using std::cout;
using std::endl;
using std::placeholders::_1;
using std::placeholders::_2;

void f (int x, int y, int z) {
  cout << x << " " << y << " " << z << endl;
}

void fb (int n1, int n2, int n3, const int& n4, int n5) 
{
  cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << endl;
}

int
main ()
{
  function<void()> f_call = bind (f, 1, 2, 3);
  f_call (); //Equivalent to f (1, 2, 3)
  function<void(int)> f_call_reord = bind (f, 1, _1, 3);
  f_call_reord (2); // f (1, 2, 3)

  int n = 7;
  auto f1 = bind (fb, _2, _1, 42, std::cref(n), n);
  n = 10;

  f1(1, 2, 1001);
}

