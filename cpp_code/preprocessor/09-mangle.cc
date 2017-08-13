#define VARIABLE 3
#define PASTER(x,y) x ## _ ## y
#define EVALUATOR(x,y)  PASTER(x,y)
#define NAME(fun) EVALUATOR(fun, VARIABLE) 
extern void NAME(mine)(char *x);

