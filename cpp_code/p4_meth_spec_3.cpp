#include <cstdio>

using namespace std;

template <typename T1, typename T2>
class A
{
  public:
     void func(void) { internal_func (T1()); }
  private:
    template< class V >  
    void internal_func (V) 
      { printf ("forall\n"); }

    void internal_func (int) 
      { printf ("forint\n"); }
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

