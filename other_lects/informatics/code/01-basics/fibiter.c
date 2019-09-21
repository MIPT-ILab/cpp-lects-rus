#include <stdio.h>

unsigned long long fib (unsigned n, unsigned m) {
  unsigned long long first = 0ull, second = 1ull; int idx;
  if (n == 0) return 0ull;
  for (idx = 2; idx <= n; ++idx) {
    unsigned long long tmp = second;
    second = (second + first) % m;
    first = tmp;
  }
  return second;
}

int main () {
  int i, j;
  for (j = 2; j < 10; ++j) {
    printf("%d:", j);
    for (i = 0; i < 20; ++i) 
      printf("%llu ", fib(i, j));
    printf("\n");
  }
}
