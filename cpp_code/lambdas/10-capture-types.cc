#include <iostream>

using std::cout;
using std::endl;

int 
foo (int a, int b)
{
  auto fval = [a, b](int x) { return a + b*x; }; 
  auto fref = [&a, &b](int x) { a = x;  return a + b*x; };
  auto fmval = [a](int x) mutable { a += x; return a; }; 
  auto fmref = [&a](int x) mutable { a += x; return a; };
  auto faval = [=](int x) { return a + b*x; }; 
  auto faref = [&](int x) { return a + b*x; };
  auto fmaval = [=](int x) mutable { a += b*x; return a; };
  auto fmaref = [&](int x) mutable { a += b*x; return a; };
  auto freval = [la = a](int x) { return la + x; }; 
  auto freref = [&la = a](int x) { la += x; return la; };
  auto fmixcap = [=, &la = a](int x) { la += x + b; return la; };

  cout << fval (1) << endl;
  cout << fref (1) << endl;
  cout << fmval (1) << endl;
  cout << fmref (1) << endl;
  cout << faval (1) << endl;
  cout << faref (1) << endl;
  cout << fmaval (1) << endl;
  cout << fmaref (1) << endl;
  cout << freval (1) << endl;
  cout << freref (1) << endl;
  cout << fmixcap (1) << endl;
  return (a + b);
}

int
main (void)
{
  cout << foo (1, 1) << endl;
}

