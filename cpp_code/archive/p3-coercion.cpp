#include <iostream>

using std::cout;
using std::endl;

class Evil;

class Good
{
public:
  Good () = default;
  template <typename T>
  Good (const T &e) { cout << "Good (const T &e)" << endl; }
};

class Evil
{
public:
  Evil () = default;
  template <typename T>
  Evil (const T &g) { cout << "Evil (const T &g)" << endl; }
};

int
main (void)
{
  Good g;
  Evil e = g;
  Good gprime = e;
  return 0;
}
