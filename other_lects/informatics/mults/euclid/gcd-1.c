#include <stdio.h>

// gcd(a, 0) = a
// gcd(a, b) = gcd(b, a % b)
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int a;  
  a = gcd(18, 12);
  printf("%d\n", a);
}