struct S {
  int data_;
  using inner = int;
  S& operator++()
#ifndef BAD
  noexcept 
#endif
  { ++data_; return *this; }
};

int operator+(S s, int x) {
  return x + s.data_;
}

template <typename T>
requires requires(T a) {
  { a + 1 } -> typename T::inner; 
  requires noexcept(++a);
  requires sizeof(T) == 4;
}
int foo(T x) {
  return ++x + 1;
}

int
main() {
  S s;
  foo(s);
}
