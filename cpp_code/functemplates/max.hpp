#ifndef MAX_GUARD_
#define MAX_GUARD_

template <typename T> T __attribute__((noinline))
max (T x, T y)
{
  return (x > y) ? x : y;
}

extern int foo (int x, int y);
extern int bar (int x, int y);

#endif

