template <typename T> struct TD;

template <typename T> 
void foo (T *const & t) {
  TD<T> tType;
  TD<decltype(t)> tParam;
}


int main (void) {
  int x = 42;
  const int &y = x;
  const int *z = &x;

  auto t = z;
  TD<decltype(t)> tType;

//  foo (&x);
//  foo (&y);
  foo (z);
}

