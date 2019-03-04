#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

enum {
  NFST = 10
};

char
pi_number() {
  // TODO: your code here
}

int
main() {
  int i;
  char firstdigs[NFST] = {1,1,0,0,1,0,0,1,0,0};

  for (i = 0; i < NFST; ++i) {
    char nextdig = pi_number();
    if (nextdig != firstdigs[i]) {
      printf("Error in digit %d\n", i);
      abort();
    }
  }
  
  return 0;
}
