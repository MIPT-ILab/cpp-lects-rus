#include <iostream>
#include <cstdlib>

template<int M, int K, int S> struct Unit
{ // a unit in the MKS system
 enum { m=M, kg=K, s=S };
};

template<typename Unit> // a magnitude with a unit
struct Value
{
 double val; // the magnitude
 explicit constexpr Value(double d = 0.0) : val(d) {} // construct a Value from a double
};

using Speed = Value<Unit<1,0,-1>>;  // meters/second type
using Acceleration = Value<Unit<1,0,-2>>;  // meters/second/second type
using Meter = Unit<1,0,0>; // unit: meter
using Second = Unit<0,0,1>; // unit: sec
using Second2 = Unit<0,0,2>; // unit: second*second

constexpr Value<Meter> operator"" _m(long double d)
 // a f-p literal suffixed by ‘s’
{
 return Value<Meter> (d);
}

constexpr Value<Second> operator"" _s(long double d)
 // a f-p literal suffixed by ‘s’
{
 return Value<Second> (d);
}

constexpr Value<Second2> operator"" _s2(long double d)
 // a f-p literal suffixed by ‘s2’
{
 return Value<Second2> (d);
}

// here goes some operator / overloads

int main()
{
	Speed sp1 = 100.0_m/9.8_s; // very fast for a human
//	double sp2 = 100_m/9.8_s2; // error (m/s2 is acceleration)
//	double sp3 = 100/9.8_s; // error (speed is m/s and 100 has no unit)
	double acc = sp1/0.5_s; // too fast for a human

	return EXIT_SUCCESS;
}
