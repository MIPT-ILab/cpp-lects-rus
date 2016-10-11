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

int
main (void)
{
  const Empty *c;
  foo (c);  
}

