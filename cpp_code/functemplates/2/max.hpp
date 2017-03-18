#ifndef MAX_GUARD_
#define MAX_GUARD_

template <typename T> T
max (T x, T y)
{
  return (x > y) ? x : y;
}

// block instancing everywhere
extern template int max<int> (int, int);

extern int foo (int x, int y);
extern int bar (int x, int y);

#endif

