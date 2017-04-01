#include <iostream>
#include <utility>

using std::cout; 
using std::endl;

struct Complex
{
  constexpr Complex(double r = 0.0, double i = 0.0) : re(r), im(i) { }

  constexpr double real() const { return re;}
  constexpr double imag() const { return im;}

  constexpr Complex& operator+= (const Complex &rhs) 
  {
    re += rhs.re;
    im += rhs.im;
    return *this;
  }  

private:
  double re;
  double im;
};

constexpr Complex operator+ (const Complex &lhs, const Complex &rhs)
{
  Complex tmp = lhs;
  tmp += rhs;
  return tmp;
}

constexpr Complex operator "" _i( long double i )
{
  return Complex (0.0, i);
}

int 
main (void)
{
  constexpr Complex c = 0.0 + 1.0_i;
  cout << "c = " << c.real() << " + " << c.imag() << "i" << endl;
  return 0;
}

