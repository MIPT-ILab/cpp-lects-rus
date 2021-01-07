#include <assert.h>
#include <stdio.h>

struct gcd_params_t {
  int d, u, v;
};

int iabs(int x) {
  if (x < 0) return -x;
  return x;
}

void eu_divmod(int x, int y, int *pq, int *pr) {
  int q, r;
  assert(y != 0);  
  r = x % y;
  if (r < 0) r += iabs(y);
  q = (x - r) / y;
  *pr = r;
  *pq = q;
}

struct gcd_params_t gcd_result(int d, int u, int v) {
  struct gcd_params_t ret = {d, u, v};
  return ret;
}

struct gcd_params_t gcd(int m, int n) {  
  int a = m, b = n;
  int uold = 1, vold = 0, u = 0, v = 1;
  
  while(b != 0) {
    int r, q, t, s;
    eu_divmod(a, b, &q, &r);
    assert(m * uold + n * vold == a);
    assert(m * u + n * v == b);
    a = b; b = r;
    t = u; s = v;
    u = uold - q * u;
    v = vold - q * v;
    uold = t; vold = s;
  }
  
  return gcd_result(a, uold, vold);  
  // return (struct gcd_params_t){a, uold, vold}; // C99
}

int main() {
  int a, b, d;
  scanf("%d%d", &a, &b);  
  struct gcd_params_t result = gcd(a, b);
  assert(a * result.u + b * result.v == result.d);
  printf("gcd = %d, u = %d, v = %d\n", result.d, result.u, result.v);
  return 0;
}
