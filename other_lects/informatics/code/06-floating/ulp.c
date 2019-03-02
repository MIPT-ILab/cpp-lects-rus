#include <assert.h>
#include <math.h>
#include <stdio.h>

int
main () {
  float d0, d1;
  d0 = 1.0f;
  d1 = nextafterf(d0, d0 + 1.0f);
  printf("%.8f\n", d1 - d0);
  
  d0 = 1.0f / 3.0f;
  assert (d0 * 3.0f != 1.0f);  

  d1 = d0;
  if (d1 * 3.0f > 1.0f)
    d1 = nextafterf(d1, d1 - 1.0f);
  else 
    d1 = nextafterf(d1, d1 + 1.0f);

  printf("%.8f %.8f\n", d0, d1);
}