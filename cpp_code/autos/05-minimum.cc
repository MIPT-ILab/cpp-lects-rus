#include <iostream>

using std::cout;
using std::endl;

#if defined(INVESTIGATE)
template <typename T> struct TD;
#endif

template <typename T, typename U>
auto min (T x, U y) {
  return (x <= y) ? x : y;
}

int
main ()
{
  auto t1 = min (1, 2.0);
  auto t2 = min (1.0, 2);
  auto t3 = min (1, 2);

#if defined(INVESTIGATE)
  TD<decltype(t1)> tt1;
  TD<decltype(t2)> tt2;
  TD<decltype(t3)> tt3;
#endif

  cout << t1 << " " << t2 << " " << t3 << endl;
}

