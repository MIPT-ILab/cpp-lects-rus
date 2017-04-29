#include <cfenv>
#include <iostream>

using std::cerr;
using std::endl;
using std::fesetround;

constexpr float ct = 1.0f / 3.0f;

void __attribute__ ((noinline))
magic_func (float x, float y)
{
//  fesetround (FE_DOWNWARD);
  float rt = x / y;
  if (ct != rt) 
    cerr << "Failure: " << ct << " != " << rt << endl;  
}

int
main ()
{
  magic_func (1.0, 3.0);
}

