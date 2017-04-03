#include <iostream>
#include <utility>

using std::enable_if;
using std::cout;
using std::endl;

template <typename T, typename = typename enable_if<(sizeof(T) > 4)>::type>
void
  foo (T x) {
  cout << x << " greater then 4" << endl;
}

template <typename T, typename = typename enable_if<(sizeof(T) <= 4)>::type>
void
foo (T x, int dummy = 0) {
  cout << x << " less then 4" << endl;
}

int
main ()
{
  char c = 'A';
  double d = 42.0;

  foo (c);
  foo (d);
}


