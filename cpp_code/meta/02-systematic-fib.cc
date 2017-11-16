#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::integral_constant;
using std::size_t;

template<size_t N> struct fibonacci :
  integral_constant <size_t,
                     fibonacci<N-1>{} +
                     fibonacci<N-2>{}> {};

template<> struct fibonacci<1> : 
  integral_constant<size_t, 1> {};

template<> struct fibonacci<0> : 
  integral_constant<size_t,0> {};

int
main ()
{
  cout << fibonacci<8>{} << endl;
}

