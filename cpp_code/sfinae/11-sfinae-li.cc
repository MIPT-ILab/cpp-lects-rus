#include <iostream>

using std::cout;
using std::endl;

int __attribute__ ((noinline)) 
use (int n) 
{ 
  cout << n << endl; 
}

int 
negate(int i) 
{ 
  return -i; 
} 

#if defined(CASE1)

template <typename T> 
T
negate(const T& t) 
{
  typename T::value_type n = -t();
  use (n);
  return n;
};

#else

template <typename T> 
typename T::value_type 
negate(const T& t) 
{
  auto n = -t();
  use (n);
  return n;
}

#endif

int
main ()
{
  auto ret = negate (2.0);
  cout << ret << endl;
}

