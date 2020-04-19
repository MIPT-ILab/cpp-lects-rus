#define VARIABLE 3 

#define CONCAT(X, Y) X ## _ ## Y
#define PROXY(X, Y) CONCAT(X, Y)
#define NAME(X) PROXY(X, VARIABLE)

extern void NAME(mine)(char *x);
