#include <cstdio>

using namespace std;

template <typename T1, typename T2>
class A
{
    template <typename T> void internal_func(T dummy) { printf ("forall\n"); }
    void internal_func(int dummy) { printf ("for int\n"); }
public:
   void func() {T1 dummy; internal_func(dummy);}

};

int
main (void)
{
  A <int, double> a;
  A <float, double> b;

  a.func(); /* for int */
  b.func(); /* forall */

  return 0;
}
