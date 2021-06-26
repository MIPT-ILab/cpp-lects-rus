#include <assert.h>
#include <stdio.h>

int fact(int x);

int main() {
  int n, res;
  res = scanf("%d", &n);
  assert(res == 1);
  n = fact(n);
  printf("%d\n", n);
}
