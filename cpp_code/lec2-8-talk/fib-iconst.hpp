#include <utility>

template <unsigned N>
using icu = std::integral_constant <unsigned, N>;

namespace IConst
{

template <unsigned N>
struct Fibonacci : icu <Fibonacci<N - 1>::value + Fibonacci<N - 2>::value> {};

template <> struct Fibonacci<0> : icu<0> {};
template <> struct Fibonacci<1> : icu<1> {};

}

