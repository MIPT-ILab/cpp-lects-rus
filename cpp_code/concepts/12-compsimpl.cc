template <typename T> constexpr int somepred() { return 14; }

template <typename T> requires (somepred<T>() == 42)
bool foo (T&& lhs, T&& rhs) { return lhs < rhs; }

template <typename T> 
requires requires (T t) { somepred<T>() == 42; }
bool bar (T&& lhs, T&& rhs) { return lhs < rhs; }

int
main () {
#ifdef BAD
  foo(1, 2);
#else  
  bar(1, 2);
#endif
}