/* Operator overloading */
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

class Complex
{
public:
  Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

  double get_real(void) const { return re; }
  double get_imag(void) const { return im; }

private:
  double re, im;  
};

Complex operator+ (const Complex &x, const Complex &y) 
{ 
  return Complex(x.get_real() + y.get_real(), x.get_imag() + y.get_imag()); 
}

Complex operator* (const Complex &x, const Complex &y) 
{ 
  return Complex(x.get_real() * y.get_real() - x.get_imag() * y.get_imag(), 
                 x.get_real() * y.get_imag() + x.get_imag() * y.get_real()); 
}

void test_simple_cases(void)
{
  Complex a = Complex(1.0, 3.1);
  Complex b = Complex(1.2, 2.0);
  Complex c = b;
  a = b + c;
  b = b + c * a;
  c = a * b  + Complex(1, 2);

  printf("%lf + %lf * i\n", c.get_real(), c.get_imag());
}

void test_complex_cases(void)
{
  Complex a = Complex(1.0, 3.1), b;
  b = a + 2.0; /* ok */
  b = 2.0 + a; /* ok again! */

  printf("%lf + %lf * i\n", b.get_real(), b.get_imag());  
}

int main(void)
{
  test_simple_cases();
  test_complex_cases();
  return 0;
}

