#include <cstdlib>
#include <utility>

using std::integral_constant;
using std::size_t;

namespace IConst {

template<size_t N>
struct factorial : integral_constant<size_t, N * factorial<N - 1>{}> {};
template<> struct factorial<1> : integral_constant<size_t, 1> {};
template<> struct factorial<0> : integral_constant<size_t, 1> {};

}