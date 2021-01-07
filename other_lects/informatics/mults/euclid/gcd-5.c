#include <assert.h>
#include <stdio.h>

int gcd_steps(int a, int b) {
  int nsteps = 0;
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
    nsteps += 1;
  }
  return nsteps;
}

int gcd_height(int a) {
  int i, h = 0;
  for (i = 1; i < a; ++i) {
    int s = gcd_steps(a, i);
    if (s > h)
      h = s;
  }
  return h;
}

int main() {
  int n, curheight = 1;  
  for (n = 1; ; n += 1) {
    int h = gcd_height(n);
    if (h >= curheight) {
      printf("Minimal with h = %d is: %d\n", curheight, n);
      curheight += 1;
    }
    if (curheight > 10)
      break;
  }
  return 0;
}
