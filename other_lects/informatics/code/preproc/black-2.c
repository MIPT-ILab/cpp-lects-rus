#define CALL(X,Y) X(Y)
#define FOO(X) X
#define BAR(X) #X

CALL(FOO, BAR)(!!!) // expands
CALL(FOO, CALL)(1, 2) // not expands
