#include <iostream>

using std::cout;
using std::endl;

struct C1 {
  C1() { cout << "C1 default" << endl; }
};

struct C2 {
  C2() { cout << "C2 default" << endl; }
};

template <typename ... Mixins>
struct mixture : public Mixins ... {
  mixture(Mixins... ms) : Mixins(ms)... {};
};

int
main (void)
{
  mixture<C1, C2> m(C1{}, C2{});
  mixture<> n;
}

