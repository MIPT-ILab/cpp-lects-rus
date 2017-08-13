#include <iostream>

using std::cout;
using std::endl;

#if !defined(CHECK_LEVEL)
#define CHECK_LEVEL 0
#endif

#if (CHECK_LEVEL > 0)
  void check () { cout << "checking at " << CHECK_LEVEL << endl; }
#else
  void check() {}
#endif

int
main ()
{
  check();
}

