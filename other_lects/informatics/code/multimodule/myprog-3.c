#include <stdio.h>
#include "mypow.h"

int
main () {
  printf("3^7 == %lld\n", ipow(3, 7));
  printf("4^13 == %lld\n", ipow(4, 13));
  printf("17^6 == %lld\n", ipow(17, 6));
  return 0;
}