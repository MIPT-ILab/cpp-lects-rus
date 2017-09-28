#include <iostream>

using std::cout;
using std::endl;

#if defined(INVESTIGATE)
template <typename T> struct TD;
#endif

template <typename T, typename U>
auto min (T x, U y) 
#if !defined (POST11)
  -> decltype((x <= y) ? x : y) 
#endif
{
  return (x <= y) ? x : y;
}

int
main ()
{
  decltype(auto) t1 = min (1, 0.7);
  decltype(auto) t2 = min (0.7, 1);
  decltype(auto) t3 = min (1, 2);
  decltype(auto) t4 = min (1.5, 2.5);

#if defined(INVESTIGATE)
  TD<decltype(t1)> tt1;
  TD<decltype(t2)> tt2;
  TD<decltype(t3)> tt3;
  TD<decltype(t4)> tt4;
#endif

  cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
}

