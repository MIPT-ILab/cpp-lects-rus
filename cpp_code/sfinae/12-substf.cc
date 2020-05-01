#include <boost/type_index.hpp>

#include <iostream>

namespace ti = boost::typeindex;

template<typename T> typename T::ElementT 
at(T const& a, int i) {
  return a[i];
}

#if defined(CORR)

template<typename T> 
auto at(T const& a, int i) -> decltype(a[i]) {
  return a[i];
}

#endif

double f(int *p) { 
  std::cout << "Ooops";
}

int f(int *p) { 
  std::cout << ti::type_id_with_cvr<decltype(at(p, 7))>().pretty_name() << std::endl;
  return at(p, 7);
}

int main() {
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  f (a);
}

