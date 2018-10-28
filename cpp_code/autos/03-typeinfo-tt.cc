#include <typeinfo>
#include <iostream>

using std::cout;
using std::endl;

struct Empty {};

template<typename T> class Type2Type {};

template <typename T>
void
foo (const T& t) {
  // use c++filt -t
  Type2Type<decltype(t)> t2t;
  cout << typeid(t2t).name() << endl;
}

int
main (void)
{
  const Empty *c;
  foo (c);  
}

