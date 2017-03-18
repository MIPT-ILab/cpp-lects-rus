#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

using std::abs;
using std::cout;
using std::endl;

bool 
abssort_predicate (float a, float b) 
{
  return abs(a) < abs(b);
}

void 
abssort(float *x, unsigned N) 
{
  std::sort (x, x + N, abssort_predicate);
}

int
main ()
{
  float test[] {-4.0f, -2.0f, 1.0f, 3.0f};
  const int test_size = sizeof(test)/sizeof(float);
  abssort (test, test_size);
  for (int n = 0; n != test_size; ++n)
    cout << test[n] << " ";
  cout << endl;
}

