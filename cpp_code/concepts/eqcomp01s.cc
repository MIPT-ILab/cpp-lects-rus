#include <type_traits>

template <typename T, typename U, typename = void>
struct is_equality_comparable : std::false_type {};

// Wow, so C++
template <typename T, typename U>
struct is_equality_comparable <T, U, 
  typename std::enable_if <
    true,
    decltype ((void)(std::declval<T&>() ==  std::declval<U&>()), (void) 0)>::type
  > : std::true_type {};

// and lets use it:

template <typename T>
constexpr int somepred() {
  return 14;
}

template <typename T, typename U>
requires is_equality_comparable<T, U>::value &&
         (somepred<T>() == 14) || (somepred<U>() == 88)
bool check (T &&lhs, U &&rhs);

struct noeq {
  noeq (int x) {}
};

int main (void) {
  check (1, 1);
  check (1, 1.0);
  check (1, noeq(1));
  return 0;
}

