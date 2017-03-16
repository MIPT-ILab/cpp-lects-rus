#include <iostream>

using std::cout;
using std::endl;

template <typename T> 
void printout (T x)
{
  cout << x << endl;
}

struct expand_type 
{
  template <typename... T> expand_type(T...) {}
};

template <typename... T>
void lvisualize(T... args)
{
  /* void() is to prevent malicious "operator," overloads, 
     which cannot exist for void types */
  expand_type {(printout(args), void(), 0)... };
}

auto main () -> int
{
  lvisualize ();
  lvisualize (1, '2', 3.0, "4");
  return 0;
}

