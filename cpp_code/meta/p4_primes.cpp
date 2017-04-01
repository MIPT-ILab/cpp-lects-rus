// TemplateTest.cpp
#include "stdio.h"

template <int i>
struct NthPrime
{
  template <int p>
  struct is_prime
  {
    template <int n>
    struct n_divisors
    {
      template <int N, int M>
      struct is_divisor
      {
        enum { val = is_divisor <N, M - 1>::val + ((N%M)==0) };
      };
    
      template <int N>
      struct is_divisor <N,1>
      {
        enum { val = 0 };
      };
    
      enum { val = is_divisor <n, n-1>::val };
    };
    enum { val = (n_divisors <p>::val == 0) };
  };

  template <int n, int m>
  struct search_step
  {
    enum { val = search_step <n - (is_prime <m>::val), m + 1>::val };
  };

  template <int m>
  struct search_step <1, m>
  {
    enum { val = m-1 };
  };

  enum { val = search_step <i, 3>::val };
};

int 
main (void)
{
  printf ("prime #6 = %d\n", NthPrime<6>::val);
  return 0;
}

