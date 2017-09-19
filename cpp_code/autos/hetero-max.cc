#include <iostream>

using std::cout;
using std::endl;

#if defined (NAIVE)
template <typename T, typename U>
T
max (T x, U y)
{
  return x > y ? x : y;
}
#elif defined (CTYPE)
template <typename T, typename U>
typename std::common_type<T, U>::type
max (T x, U y)
{
  return x > y ? x : y;
}
#else
template <typename T, typename U>
auto
max (T x, U y)
{
  return x > y ? x : y;
}
#endif

int
main ()
{
  cout << max (2, 1.5) << " " 
       << max (1, 1.5) << " "
       << max (2.0, 1.5) << " "
       << max (1, 2) << " "
       << endl;
}
