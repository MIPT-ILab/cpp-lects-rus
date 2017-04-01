#include <stdio.h>

template <typename T, typename U> void 
swap (T& t, U& u) 
{ 
  auto tmp = t; 
  t = (T) u; 
  u = (U) tmp; 
} 

const int a = 0;
const float b = 0.0;

int
main ()
{
  const int *x = &a; 
  const float *y = &b; 
  swap (x, y);
  printf ("%d, %g\n", *x, (double)(*y));

#if 0
  decltype("Apple") a = "Apple"; 
  decltype("Pear") p = "Pear"; 
  swap (a, p); 
#endif
}

