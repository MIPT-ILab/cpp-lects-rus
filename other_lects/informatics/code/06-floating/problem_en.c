#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double a, b, c;

struct func_deriv {
  double f, d;
};

static struct func_deriv func(double x) {
  struct func_deriv res;
  res.f = a * x * x * sin(x) + b * x * cos(x) + c;
  res.d = 2 * a * x * sin(x) + a * x * x * cos(x) + b * cos(x) - b * x * sin(x);
  return res;
}

typedef struct func_deriv (*func_t)(double);

enum { MAX_ITERCOUNT = 100 };

static double newton(func_t f, double x, double prec) {  
  struct func_deriv fval = f(x);
  int itercount = 0;
  
  #ifdef VISUALIZE
  printf("%lf %lf %lf\n", x, fval.f, fval.d);
  #endif
  
  
  while(fabs(fval.f) > prec) {    
    x = x - fval.f / fval.d;
    fval = f(x);

    #ifdef VISUALIZE
    printf("%lf %lf %lf\n", x, fval.f, fval.d);
    #endif
    
    itercount++;
    if ((itercount > MAX_ITERCOUNT) ||
        (fabs(fval.d) < DBL_EPSILON)) {
      printf("0.0");
      exit(0);
    }
  }
  
  return x;
}

int
main() {
  double x, sol;
  int res;
  double prec = 1e-5;
  
  res = scanf("%lf%lf%lf%lf", &a, &b, &c, &x);
  assert(res == 4);
 
  sol = newton(func, x, prec);
  printf("%.5lf\n", sol); 
}
