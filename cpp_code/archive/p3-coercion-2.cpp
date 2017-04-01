#include <iostream>

using std::cout;
using std::endl;

class Good
{
};

class Evil
{
public:
  Evil () = default;

  template <typename T>
  Evil (const T &) { cout << "Evil (const T &)" << endl; }

  template <typename T>  
  operator T () { cout << "operator T ()" << endl; }
};

int
main (void)
{
  Good g;
  Evil e = g;
  Good gprime = e;
  return 0;
}
