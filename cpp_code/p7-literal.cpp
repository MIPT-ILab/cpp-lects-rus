#include <cstdio>
#include <utility>

struct Complex
{
public:
  constexpr Complex(double r = 0.0, double i = 0.0) : re(r), im(i) { }

  class Imaginary {}; /* tag */
  explicit constexpr Complex(Imaginary, double i) : re (0.0), im (i) {}

  constexpr double real() { return re;}
  constexpr double imag() { return im;}

  friend constexpr Complex operator+ (const Complex lhs, const Complex rhs);  

private:
  double re;
  double im;
};

constexpr Complex operator+ (const Complex lhs, const Complex rhs)
{
  return Complex(lhs.re+rhs.re, lhs.im+rhs.im);
}

constexpr Complex operator "" _i( long double i )
{
  return Complex{Complex::Imaginary{}, static_cast<double>(i)};
}

int 
main (void)
{
  constexpr Complex c = 0.0 + 1.0_i;

  std::printf ("c: (%g, %g)\n", c.real(), c.imag());
  return 0;
}

