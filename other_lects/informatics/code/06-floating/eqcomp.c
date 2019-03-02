#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void
eqcomp() {
  double d1, d2, d3;
  d1 = 10.0;
  d2 = sqrt(d1);
  d3 = d2 * d2;
  if (d1 != d3) {
    printf("d1 (%.15lf) != d3 (%.15lf)\n", d1, d3);
  }
}

void
additions () {
  int i;
  double h, cosval;

  for (i = 1; i < 20; ++i) {
    h = pow(10.0, -i);
    cosval = (sin(1.0 + h) - sin(1.0)) / h;
    printf("%d:\t%.15lf\n", i, cosval);
  }
  
  cosval = cos(1.0);
  printf("True result: %.15lf\n", cosval);
}

void
finiterange() {
  float f, nextf, fone, feps, fenext;
  double d, nextd;
  
  f = 16777216.0f; // 2^24
  nextf = f + 1.0f;

  fone = 1.0f;
  feps = 0.00000005f;
  fenext = fone + feps;

  d = 9007199254740992.0; // 2^53
  nextd = d + 1.0;
  
  printf("f: %8.0lf\t\tnextf: %8.0lf\n", f, nextf);
  printf("feps: %.8f\tfenext: %.8f\n", feps, fenext);
  printf("d: %16.0lf\tnextd: %16.0lf\n", d, nextd);
}

void
infnan() {
  double d = 1.79e+308;
  double infd = 2.0 * d;
  double infdzero = infd * 0.0;
  printf("d: %le\tinfd: %le\tinfdzero: %le\n", d, infd, infdzero);
}

int 
main(int argc, char **argv) {
  int ntry;

  if (argc < 2) {
    printf("usage: %s <number>\n", argv[0]);
    return 0;
  }
  
  ntry = strtol(argv[1], NULL, 10);
  
  switch(ntry) {
    case 0: eqcomp(); break;
    case 1: additions(); break;
    case 2: finiterange(); break;
    case 3: infnan(); break;
    default: printf("Unknown test\n"); break;
  }
  
  return 0;
}

