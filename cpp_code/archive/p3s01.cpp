#include <cstdio>

using namespace std;

template <typename T> inline const T 
max (const T a, const T b)
{
  return (a > b) ? a : b;
} 

template<typename T>
typename T::ElementT at (T const& a, int i) {
  return a[i];
}

#if 0
template <class T>
struct item_return{ typedef typename T::ElementT type; };

template <>
struct item_return<int*> { typedef int type; };

template<typename T> 
typename item_return<T>::type at (const T a, int i) 
{ 
    return a[i]; 
} 

template <>
int at (int *a, int i)
{
  return a[i];
}
#endif

template<typename T>
auto at (T const& a, int i) -> decltype(a[i]) {
  return a[i];
}


int
f (int *p)
{
  int x = at(p, 7); /* boom! */
  return x; 
}

int
main (void)
{
  fprintf (stderr, "max (1.2, 2.3) == %g, max (4, 3) == %d\n", max (1.2, 2.3), max (4, 3));
#if 0
  int g = max(1, 1.0);
#endif
  return 0;
}

