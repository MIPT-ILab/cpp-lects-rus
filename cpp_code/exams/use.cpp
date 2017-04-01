#include "template.h" 
#include "allmax.h" 
#include <stdio.h>

int 
main () 
{
  printf ("MAX(5, 6) = %d\n", TEMPLATE(max,int)(5, 6)); 
  printf ("MAX(5.0f, 6.0f) = %f\n", TEMPLATE(max,float)(5.0f, 6.0f)); 
  return 0;
}

