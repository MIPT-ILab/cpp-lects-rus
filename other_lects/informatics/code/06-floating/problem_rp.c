#include <assert.h>
#include <fenv.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned as_uint(float f) {
  return *(unsigned *)&f;
}

float as_float(unsigned u) {
  return *(float *)&u;
}

// IEEE754 floating point parts
enum {
  // sign
  SGN_OFFSET = 31,
  SGN_MASK = 1,

  // exp
  EXP_OFFSET = 23,
  EXP_MASK = 0xFF,

  // frac
  FRAC_OFFSET = 0,
  FRAC_MASK = 0x7FFFFF,

  // to invert every odd bit
  INV_MASK = 0xAAAAAAAA
};

void print_exp_frac(float f) {
  unsigned exp, frac;
  unsigned u = as_uint(f);
  exp = (u >> EXP_OFFSET) & EXP_MASK;
  frac = (u >> FRAC_OFFSET) & FRAC_MASK;
  printf("0x%x 0x%x ", exp, frac);
}

int main() {
  int res;
  float f, g, upquot, quot;

  res = scanf("%f%f", &f, &g);
  assert(res == 2);
  
  fesetround(FE_UPWARD);
  upquot = f / g;
  
  fesetround(FE_DOWNWARD);
  quot = f / g;
  
  // print lower app
  print_exp_frac(quot);
  
  if (upquot != quot) {
    // print next after
    upquot = nextafterf(quot, f);
    print_exp_frac(upquot);
  }
  
  printf("\n");
}
