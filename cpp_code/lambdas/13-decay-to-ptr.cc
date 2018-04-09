#include <iostream>

using std::cout;
using std::endl;

typedef int (*fptr_t)();

fptr_t 
create() 
{
  fptr_t fptr = [] { return 2; };
  return fptr;
}

template <typename T>
T apply (T(*f)())
{
  return f();
}

int 
main ()
{
   fptr_t f = create();
   cout << apply (f) << endl;
#ifndef FIXES
   cout << apply ([] { return 3; }) << endl;
#else
   cout << apply (static_cast<fptr_t>([] { return 3; })) << endl;
   cout << apply (+[] { return 3; }) << endl;
#endif
}

