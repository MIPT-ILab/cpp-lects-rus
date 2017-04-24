#include <iostream>

using std::cout;
using std::endl;

// upper bound for  logN = 
//     (position of elder set bit) if exact log, or 
//     (position of elder set bit)+1 otherwise
constexpr size_t 
static_log_helper (size_t N, size_t pos)
{
  return ((N & (1ull << pos)) == (1ull << pos) || pos == 0) ? 
    (N == (1ull << pos) ? pos : pos + 1) :
      static_log_helper (N, pos - 1);
}

constexpr size_t
static_log (size_t N) 
{
  return (N != 0) ? static_log_helper (N, sizeof(size_t) * CHAR_BIT - 1) :
         throw "N == 0 not supported";
}

int 
main ()
{
  constexpr int log128 = static_log(128);
  cout << log128 << endl;

#ifdef ERR
  constexpr int log0 = static_log(0);
  cout << log0 << endl;
#endif

#ifdef RT
  for (size_t i = 1; i < 100; ++i)
    cout << i << ": " << static_log(i) << endl;
#endif
}

