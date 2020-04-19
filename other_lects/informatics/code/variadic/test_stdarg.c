#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int n, ...) {
  int res = 0, i;
  va_list vl;
  
  assert(n > 0);

  va_start(vl, n);
  for (i = 0; i < n; ++i) {
    res += va_arg(vl, int);
  }

  va_end(vl);
  return res;
}

int my_printf_n(int n, const char *format, ...) {
  int res, i;
  va_list vl;
  va_start(vl, format);
  assert(n > 0);
  for (i = 0; i < n; ++i) {
    va_list vl2;
    va_copy(vl2, vl);
    res += vprintf(format, vl2);
    va_end(vl2);
  }
  va_end(vl);
  return res;
}

int main() {
  int x = sum(8, 10, 20, 30, 40, 41, 42, 43, 44);
  my_printf_n(4, "%d\n", x);
}

