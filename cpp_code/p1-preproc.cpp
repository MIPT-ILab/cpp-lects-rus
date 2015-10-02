#define VARIABLE 3

/* ... some magic? ... */
// no: 
// #define NAME(fun) fun ## _ ## VARIABLE

// no:
// #define PASTER(x,y) x ## _ ## y
// #define NAME(fun) PASTER(fun, VARIABLE)

#define PASTER(x,y) x ## _ ## y
#define EVALUATOR(x,y)  PASTER(x,y)
#define NAME(fun) EVALUATOR(fun, VARIABLE)

extern void NAME(mine)(char *x);
/* creates mine_3 function */

