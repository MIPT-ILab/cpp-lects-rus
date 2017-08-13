#include <iostream>

using std::cout;
using std::endl;

#if defined (ENABLE_CHECKS)
  void check () { cout << "checking" << endl; }
#else
  void check() {}
#endif

int
main ()
{
  check();
}

