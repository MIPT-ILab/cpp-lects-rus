template<typename T> void foo (T);
template<typename T> void bar (T&);
template<typename T> void buz (T*);

int
main () {
  int x = 42;
  int const * const& y = &x;
  foo(y);
  bar(y);
  buz(y);
}

