#include <iostream>

using std::cout;
using std::endl;

template <typename T> 
void printout (T x)
{
  cout << x << endl;
}

template <typename... T>
void lvisualize(T... args)
{
  int x[] {(printout(args), 0)... };
}

auto main () -> int
{
  lvisualize ();
  lvisualize (1, '2', 3.0, "4");
  return 0;
}

