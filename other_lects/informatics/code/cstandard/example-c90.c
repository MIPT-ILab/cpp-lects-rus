#include <stdio.h>

static x;

main(void) {
  auto i;
  for (i = 0; i < 5; i += 2) 
    x += i;
  printf("%d\n", x);
  return 0;
}
