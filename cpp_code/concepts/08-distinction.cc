#include <iostream>
#include <utility>

#ifdef SFINAE

template <typename T, typename = std::enable_if_t<(sizeof(T) > 4)>>
void foo (T x) { std::cout << "For large" << std::endl; }

template <typename T, typename = std::enable_if_t<(sizeof(T) <= 4)>>
void foo (T x) { std::cout << "For small" << std::endl; }

#else

template <typename T> requires (sizeof(T) > 4)
void foo (T x) { std::cout << "For large" << std::endl; }

template <typename T> requires (sizeof(T) <= 4)
void foo (T x) { std::cout << "For small" << std::endl; }

#endif

int
main () {
  foo('a');
  foo(1LL);
}