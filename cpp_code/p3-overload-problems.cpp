#include <cstdio>

using namespace std;

template <typename T> void f( T x, T y) { printf ("(1)\n"); } /* (1) */
template <typename T> void f( double *x, T *y) { printf ("(2)\n"); } /* (2) */
template <typename T> void f( T *x, double *y) { printf ("(3)\n"); } /* (2) */
template <typename T1, typename T2> void f( T1 x, T2* y) { printf ("(4)\n"); } /* (4) */
template <typename T1, typename T2> void f( T1* x, T2 y) { printf ("(5)\n"); } /* (5) */
template <typename T1, typename T2> void f( T1* x, T2 *y) { printf ("(6)\n"); } /* (6) */
void f( double* x, double *y) { printf ("(7)\n"); } /* (7) */

int
main (void)
{
  double t, s;
  f (&t, &s);
  return 0;
}

