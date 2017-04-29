#include <iostream>

using std::cout;
using std::endl;

// upper bound for  logN = 
//     (position of elder set bit) if exact log, or 
//     (position of elder set bit)+1 otherwise
constexpr size_t 
static_log_helper (size_t N, size_t pos)
{
  return ((N & (1 << pos)) == (1 << pos) || pos == 0) ? 
    (N == (1 << pos) ? pos : pos + 1) :
      static_log_helper (N, pos - 1);
}

constexpr size_t
static_log (size_t N) 
{
  return static_log_helper (N, sizeof(size_t) * CHAR_BIT - 1);
}

int 
main ()
{
  constexpr size_t x = static_log(8);
  cout << x << endl;
}

