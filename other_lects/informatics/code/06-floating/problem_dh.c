#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double a, b, c;

static double func(double x) {
  return a * x * x * sin(x) + b * x * cos(x) + c;
}

typedef double (*func_t)(double);

static void swap(double *pxl, double *pxr) {
  double tmp = *pxr;
  *pxr = *pxl;
  *pxl = tmp;
}

static double dihotomy(func_t f, double xl, double xr, double prec) {  
  double fval;

  // make xl --> f(xl) < 0
  if (f(xl) > 0.0)
    swap(&xl, &xr);
  
  fval = f(xl);
  
  assert(fval < 0.0);
  assert(f(xr) > 0.0);
  
  #ifdef VISUALIZE
  printf("%lf %lf\n", xl, xr);
  printf("%lf %lf\n", f(xl), f(xr));
  #endif
  
  while(fabs(fval) > prec) {
    double xmid = (xl + xr) / 2.0;
    fval = f(xmid);
    
    #ifdef VISUALIZE
    printf("xs: %lf %lf %lf\n", xl, xr, xmid);
    printf("fs: %lf %lf %lf\n", f(xl), f(xr), f(xmid));
    #endif
    
    if (fval > 0.0)
      xr = xmid;
    else
      xl = xmid;
  }
  
  return xl;
}

int
main() {
  double N, sol;
  int res;
  double prec = 1e-7;
  
  res = scanf("%lf%lf%lf%lf", &a, &b, &c, &N);
  assert(res == 4);
  assert(N > 0);
  
  if (signbit(func(-N)) == signbit(func(N))) {
    printf("%s\n", "0.0");
    exit(0);
  }
  
  sol = dihotomy(func, -N, N, prec);
  printf("%.5lf\n", sol); 
}
