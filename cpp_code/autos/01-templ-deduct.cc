
//template<typename T> void foo (T t);

#if 0
template<typename T> void foo (T& t);
template<typename T> void foo (T* t);
#endif

template<typename T> void foo (T *const & t);

int main (void) {
  int x = 42;
  const int &y = x;
  const int *z = &x;

#if 0
  foo (x);
  foo (y);
  foo (z);
#endif

#if 1
  foo (&x);
  foo (&y);
  foo (z);
#endif
}

