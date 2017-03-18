// overloaded lambdas demo

#include <iostream>
#include <utility>

using namespace std;

template <class... F>
struct overload : F... {
//  using overload<F...>::operator();
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

