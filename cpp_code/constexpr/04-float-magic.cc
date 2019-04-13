#include <cfenv>
#include <iomanip>
#include <iostream>

using std::cerr;
using std::endl;
using std::fesetround;

constexpr float ct = 1.0f / 3.0f;

void __attribute__ ((noinline))
magic_func (float x, float y)
{
#ifdef BUGGY
  fesetround (FE_DOWNWARD);
#endif
  float rt = x / y;
  if (ct != rt) 
    cerr << "Failure: " << std::setprecision(9) << ct << " != " << rt << endl;  
}

int
main ()
{
  magic_func (1.0, 3.0);
}

