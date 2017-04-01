#include <iostream>

using std::cout;
using std::endl;

template<typename T, int N> struct Stars {
  typedef typename Stars<T, N-1>::type *type;
}; 

template<typename T> struct Stars<T, 0> {
  typedef T type;
};

// here goes instances

typedef Stars<int, 1>::type iptr_t;
typedef Stars<int, 2>::type ipptr_t;

int
main (void)
{
  int s = 42;
  iptr_t p = &s;
  ipptr_t pp = &p;

  cout << s << " " << p << " " << pp << endl; 
}
 
