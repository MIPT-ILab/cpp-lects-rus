//-------------- eqsolve.h -- header for equation solver -----------------------
//
// methods: dihotomy, secant, newton
//
//------------------------------------------------------------------------------

#pragma once

typedef double (*func_t)(double x);

double dihotomy(func_t f, double xleft, double xright);
double secant(func_t f, double xleft, double xright);

struct func_deriv {
  double func;
  double der;
};

typedef struct func_deriv (*fder_t) (double x);

double newton(fder_t f, double x);
