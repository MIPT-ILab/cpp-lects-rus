#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::integral_constant;
using std::size_t;

template<size_t N>
struct fact : 
  integral_constant<size_t, 
                    N * fact<N - 1>{}> {}; 

template<> struct fact<0> : 
  integral_constant<size_t, 1> {};

int
main ()
{
  cout << fact<5>{} << endl;
}

