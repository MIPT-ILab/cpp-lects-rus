#include <cstdio>

using namespace std;

template <typename S, typename T>
class ABase
{
public:
  void func(void) {static_cast<S*>(this)->forall(); }
};

template <typename S>
class ABase <S, int>
{
public:
  void func(void) { static_cast<S*>(this)->forint(); }
};


template <typename T1, typename T2>
class A : public ABase <A<T1, T2>, T1>
{
  public:
    void forall () 
      { printf ("forall\n"); }

    void forint ()
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

