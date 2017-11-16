#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::integral_constant;
using std::size_t;

template <size_t n, size_t idx, size_t product> 
struct fact_rec : 
  integral_constant<size_t, 
                    fact_rec <n, idx + 1, product * idx>{}> {};

template <size_t n, size_t product> 
struct fact_rec <n, n, product> : 
  integral_constant<size_t, 
                    product * n> {};

template <size_t n> 
struct factorial : 
  integral_constant<size_t, fact_rec <n, 1, 1>{}> {};

int
main ()
{
  cout << factorial<8>{} << endl;
}
