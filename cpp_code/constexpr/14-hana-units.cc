#include <boost/hana.hpp>

#include <functional>
#include <utility>

namespace hana = boost::hana;

template <typename Unit> struct Value {
  double val;
  explicit constexpr Value(double d) : val(d) {}
  explicit constexpr operator double() const { return val; }

  // unit coercion
  template <typename Other> 
  explicit constexpr Value(Value<Other> other) : val(other.val) {
    static_assert(Unit{} == Other{}, "Dimensions incompatible");  
  }
};

template <typename D1, typename D2>
constexpr auto operator*(Value<D1> a, Value<D2> b) {
  using D = decltype(hana::zip_with(std::plus<>{}, D1{}, D2{}));
  return Value<D>{double(a) * double(b)};
}

template <typename D1, typename D2>
constexpr auto operator/(Value<D1> a, Value<D2> b) {
  using D = decltype(hana::zip_with(std::minus<>{}, D1{}, D2{}));
  return Value<D>{double(a) / double(b)};
}

using Meter = decltype(hana::tuple_c<int, 1, 0, 0>);
using Second = decltype(hana::tuple_c<int, 0, 0, 1>);
using Second2 = decltype(hana::tuple_c<int, 0, 0, 2>);
using Speed = decltype(hana::tuple_c<int, 1, 0, -1>);
using Acceleration = decltype(hana::tuple_c<int, 1, 0, -2>);

constexpr Value<Meter> operator"" _m(long double d) {
 return Value<Meter>(d);
}

constexpr Value<Second> operator"" _s(long double d) {
 return Value<Second>(d);
}

constexpr Value<Second2> operator"" _s2(long double d) {
 return Value<Second2>(d);
}

int main()
{
  auto len = 100.0_m;
  auto tm = 9.8_s;
	Value<Speed> sp1 { len / tm }; 
#if defined(BAD_UNITS)
  Value<Acceleration> ac1 { sp1 * 3.0_s };
#endif
  Value<Acceleration> ac2 { sp1 / 3.0_s };
}
