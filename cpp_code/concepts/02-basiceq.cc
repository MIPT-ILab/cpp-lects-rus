#include <string>
#include <utility>

template <typename T, typename U, typename = void>
struct is_equality_comparable : std::false_type {};
template <typename T, typename U>
struct is_equality_comparable <T, U, 
  std::void_t<decltype(std::declval<T>() == std::declval<U>())>
>: std::true_type {};

int main () {  
  static_assert(!is_equality_comparable<std::string, int>::value, "Shall be not comparable");
  static_assert(is_equality_comparable<long&, char>::value, "Shall be comparable");
}