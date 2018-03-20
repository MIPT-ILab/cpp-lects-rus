// overloaded lambdas demo

#include <iostream>
#include <utility>

using namespace std;

template <class... F>
struct overload : F... {
#if (__cplusplus >= 201703L)
  using F::operator()...;
#endif
  overload(F... f) : F(f)... {} 
};

template <class... F>
auto make_overload(F... f) {
  return overload<F...>(f...);  
}

int
main (void)
{
  auto f = make_overload (
     [](int i) { cout << "forint" << endl; },
     [](double d) { cout << "fordouble" << endl; });

  f(3);
  f(3.0);// bad

  return 0;
}

