#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "eqsolve.h"

double
func(double x) {
  return x * x * sin(x) - 5.0 * x + 7.0;
}

int
main() {
  // TODO: compare dihotomy and secant
}
