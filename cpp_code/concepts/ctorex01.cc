#include <utility>
#include <iostream>

struct Foo {

  enum {int_like, float_like} type_;

  template <typename Int, typename = std::enable_if<std::is_integral<Int>::value>>
  Foo (Int x) : type_(int_like) { std::cout << "int like: " << x; }


  template <typename Float, typename = std::enable_if<std::is_floating_point<Float>::value>>
  Foo (Float x) : type_(float_like)  { std::cout << "float like: " << x; }
};

int main () {
  Foo (1);
  Foo (5.0);
  return 1;
}

