#include <iostream>
#include <utility>

template <typename T, typename U>
requires requires(const std::remove_reference_t<T>& t,
                  const std::remove_reference_t<U>& u) {
  { t == u } -> bool&&;
  { t != u } -> bool&&;
  { u == t } -> bool&&;
  { u != t } -> bool&&;
}
bool foo(T x, U y) {
  if ((x == y) && (y != x)) {
    std::cout << "comparison is weak" << std::endl;
    return false;
  }  
  std::cout << "comparison is strong" << std::endl;
  return true;
}

struct W {};

bool operator==(W, int) { return true; }
bool operator==(int, W) { return true; }
bool operator!=(W, int) { return true; }
bool operator!=(int, W) { return true; }

int
main() {
#ifdef BAD  
  struct S{};
  auto w = foo(S{}, 1); // wrong
#endif
  auto c1 = foo(1, W{}); // corr
  auto c2 = foo(1, 2); // corr
}
