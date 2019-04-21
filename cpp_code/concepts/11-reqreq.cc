#include <string>
#include <utility>

template <typename T, typename U>
  requires requires(T t, U u) { t == u; }
bool check_eq (T &&lhs, U &&rhs) {
  return (lhs == rhs);
}

int main () {  
  check_eq(1, 2);
  check_eq(std::string{"1"}, std::string{"2"});
#ifdef BAD  
  check_eq(std::string{"1"}, 1);
#endif  
}