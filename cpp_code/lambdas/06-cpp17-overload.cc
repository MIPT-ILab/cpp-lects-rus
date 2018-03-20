// overloaded lambdas demo

#include <iostream>
#include <utility>

using namespace std;

template <class... F> struct overload : F... { using F::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;

int
main (void)
{
  auto f = overload {
     [](int i) { cout << "forint" << endl; },
     [](double d) { cout << "fordouble" << endl; }
  };

  f(3);
  f(3.0);

  return 0;
}

