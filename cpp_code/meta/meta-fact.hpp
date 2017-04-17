#include <utility>

using std::size_t;
using std::integral_constant;

template <int n>
struct factorial 
{
  enum { value = n * factorial<n - 1>::value };
};
 
template <>
struct factorial<0> {
  enum { value = 1 };
};

template <int n, int idx, int product>
struct fact_rec
{
  enum { value = fact_rec <n, idx + 1, product * idx>::value };
};

template <int n, int product>
struct fact_rec <n, n, product>
{
  enum { value = product * n };
};

template <int n>
struct factorial2
{
  enum { value = fact_rec <n, 1, 1> :: value };
};

template<size_t N>
struct factorial3 : integral_constant<size_t, N * factorial3<N - 1>{}> {};
template<> struct factorial3<1> : integral_constant<size_t, 1> {};
template<> struct factorial3<0> : integral_constant<size_t, 1> {};

