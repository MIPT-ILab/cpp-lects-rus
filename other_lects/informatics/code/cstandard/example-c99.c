#include <stdio.h>

static int x;

int main(void) {
  for (int i = 0; i < 5; i += 2) 
    x += i;
  printf("%d\n", x);
}
