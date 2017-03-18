#include <iostream>

using std::cout;
using std::endl;

// --- CRTP machinery begins

template <typename S, typename T>
class ABase {
  struct ACC : S {
    static void access_forall (S* derived) {
      void (S::*fn)() = &ACC::forall;
      (derived->*fn)();
    }
  };
public:
  void func(void) { ACC::access_forall(static_cast<S*>(this)); }
};

template <typename S>
class ABase <S, int> {
  struct ACC : S {
    static void access_forint (S* derived) {
      void (S::*fn)() = &ACC::forint;
      (derived->*fn)();
    }
  };
public:
  void func(void) { ACC::access_forint(static_cast<S*>(this)); }
};

// --- CRTP machinery ends

template <typename T1, typename T2>
struct A : public ABase <A<T1, T2>, T1>
{
protected:
  void forall ();
  void forint ();
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
