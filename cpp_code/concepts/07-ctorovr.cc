#include <iostream>
#include <utility>

struct Foo {
  template <typename Int>
  requires std::is_integral<Int>::value
  Foo (Int x) {
    std::cout << "Creating int-like object" << std::endl;
  }

  template <typename Float>
  requires std::is_floating_point<Float>::value
  Foo (Float x) {
    std::cout << "Creating float-like object" << std::endl;
  }
};

int
main () {
  Foo fint(1);
  Foo fdbl(1.0);
  
  #ifdef WRONG
  struct S{};
  
  Foo fs(S{});
  #endif
}