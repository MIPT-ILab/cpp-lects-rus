#include <iostream>

using std::cout;
using std::endl;

int
main ()
{
  for (int i = 0; i < 10000; ++i)
#if defined(USE_ENDL)
    cout << "Next line: " << i << endl;
#elif defined(USE_N)
    cout << "Next line: " << i << endl;
#else
    #error "You shall specify USE_ENDL or USE_N"
#endif
}

