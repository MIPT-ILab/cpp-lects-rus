#include <cassert>

using namespace std;

char *ap[20];
char (*pa)[20];

const int *xc1;
int const *xc2;
int * const xc3 = 0;

char* const *(*next)();
char *(*c[10])(int **p);

void (*signal(int sig, void (*func)(int)) ) (int);
typedef void (*ptr_to_func) (int);
ptr_to_func signal(int, ptr_to_func);

typedef int *ptr, (*fun)(), arr[5];
unsigned const long typedef int volatile *kumquat;
typedef int * int_ptr;
#define INT_PTR int *

INT_PTR x, y; /* x is pointer, y is int */
int_ptr w, v; /* w, v are pointers */

#define MADELUNGNACL 1.747558
const double MadelungNaCl = 1.747558; 

/* C-style */
#define kword_TOKEN 1
#define kword_LITERAL 2
#define kword_SPACE 3
/* C++-style */
enum keyword {TOKEN = 1, LITERAL, SPACE};

/* C - style */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
/* C++ - style */
template <typename T> inline const T 
max (const T a, const T b)
{
  return (a > b) ? a : b;
} 

int foo(void)
{
  int a = 5, b = 0;
  int c = MAX(++a, b);
  int d = MAX(++a, b+10);
  return c+d;
}

extern int *extern_x;
extern int extern_y[];

struct t; /* incomplete type t */

int foo(t *p);

/* definition */
struct t {
  int x;
  int y;
};

int bar(int x)
{
  int y = foo();

  x = y;
  *(&x) = y;

  return y;
}

void buz(void)
{
  char b[] = "abcdefgh", a, c;
  int i = 2, j = 3;
  a = b[i];
  c = j[b];
}

void buzptr(void)
{
  int *p;
  int c;
  c = *p;

  int x = 3;
  int *xptr = (int *) x;
}

char a[] = "abcdefgh";
char *b = "abcdefgh";

int main(void)
{
  assert (a[3] == b[3]);
  return 0;
}

