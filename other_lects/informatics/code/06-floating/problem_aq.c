#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned
as_uint(float f) {
  return *(unsigned *) &f;
}

float
as_float(unsigned u) {
  return *(float *) &u;
}

float
fast_log2(float x) {
  // TODO: your code here
}

float
fast_exp2(float x) {
  // TODO: your code here
}

float
fast_sqrt2(float x) {
  // TODO: your code here
}

int
main() {
  // TODO: check precision
  // TODO: check performance
}
