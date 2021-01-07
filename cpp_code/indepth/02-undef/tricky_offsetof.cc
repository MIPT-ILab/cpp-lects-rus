#include <iostream>

template <typename T, typename M> M get_member_type(M T::*);
template <typename T, typename M> T get_class_type(M T::*);
template <typename T, typename R, R T::*M>
constexpr std::size_t my_offset_of() {
  return reinterpret_cast<std::size_t>(&(((T*)0)->*M));
}

#define OFFSET_OF(m) my_offset_of<decltype(get_class_type(m)), \
                                  decltype(get_member_type(m)), m>()

struct S {
  int x, y;
  virtual ~S() = default;
};

int main() {
  std::cout << OFFSET_OF(&S::x) << std::endl;
}