#include <iostream>

using std::cout;
using std::endl;

template <typename S, typename T>
struct ABase {
  void func(void) {static_cast<S*>(this)->forall(); }
};

template <typename S>
struct ABase <S, int> {
  void func(void) { static_cast<S*>(this)->forint(); }
};

template <typename T1, typename T2>
struct A : public ABase <A<T1, T2>, T1>
{
  void forall (); // they are public
  void forint (); // and we want to protect them
};

template <typename T1, typename T2>
void A<T1, T2>::forall() { cout << "forall" << endl; }

template <typename T1, typename T2>
void A<T1, T2>::forint() { cout << "forint" << endl; }

int main (void)
{
  A <int, double> a;
  A <float, double> b;
  a.func(); // for int
  b.func(); // for all
}
