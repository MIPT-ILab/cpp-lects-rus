#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::integral_constant;
using std::conditional_t;
using std::size_t;

template <int N, int L = 1, int H = N, 
          int mid = (L + H + 1) / 2> 
struct Sqrt :
  integral_constant<int, 
    conditional_t<(N < mid * mid), 
                  Sqrt<N, L, mid - 1>, 
                  Sqrt<N, mid, H>> {}> {};

template <int N, int S> 
struct Sqrt <N, S, S, S> :
  integral_constant<int, S> {};

int
main ()
{
  cout << Sqrt<16>{} << endl;
}
