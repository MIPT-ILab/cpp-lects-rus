#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "eqsolve.h"

struct func_deriv func1(double x) {
  struct func_deriv ret;
  
  ret.func = x * x + exp(x) - 0.827185;
  // ret.der = ?
  
  return ret;
}

struct func_deriv func2(double x) {
  struct func_deriv ret;
  
  ret.func = x * x * sin(x) - 5.0 * x + 7.0;
  // ret.der = ?
  
  return ret;
}

int
main() {
  // TODO: solve for func1
  // TODO: try to solve for func2
}
