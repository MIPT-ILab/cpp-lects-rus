#include <typeinfo>
#include <iostream>

using std::cout;
using std::endl;

struct Empty {};

template <typename T>
void
foo (const T& t) {
  cout << typeid(t).name() << endl;
}

template <typename T> struct TD;

int
main (void)
{
  const Empty *c;
  foo (c);  
  TD<c> tParam;
}

