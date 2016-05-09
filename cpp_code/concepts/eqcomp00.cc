#include <type_traits>

template <typename T, typename U, typename = void>
struct is_equality_comparable : std::false_type {};

// Wow, so C++
template <typename T, typename U>
struct is_equality_comparable <T, U,
    decltype ((void)(std::declval<T&>() == std::declval<U&>()))
  > : std::true_type {};

template <typename T, typename U> bool 
check (T &&lhs, U &&rhs) {
  static_assert (is_equality_comparable<T, U>::value, 
                 "Comparable types required");
  return (lhs == rhs);
}

struct noeq {
  noeq (int x) {}
};

int main (void) {
  (void) check (1, 1);
  (void) check (1, 1.0);
  (void) check (1, noeq(1));
  return 0;
}

