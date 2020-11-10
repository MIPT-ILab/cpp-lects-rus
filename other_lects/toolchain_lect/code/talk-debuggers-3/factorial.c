// simple factorial program, to illustrated convoluted debug info

#include <assert.h>
#include <stdio.h>

long long fact(int x) {
  assert(x > 0);
  if (x < 3)
    return x;
  return fact(x - 1) * x;
}

int main() {
  int n, res;
  res = scanf("%d", &n);
  assert(res == 1);
  long long f5 = fact(n);
  printf("%d! = %lld\n", n, f5);
}

