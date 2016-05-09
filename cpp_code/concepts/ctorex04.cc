#include <utility>
#include <iostream>

struct Foo {

  enum {int_like, float_like} type_;

  template <typename Int> 
  requires std::is_integral<Int>::value
  Foo (Int x) : type_(int_like) 
  { 
    std::cout << "int like: " << x << std::endl; 
  }

  template <typename Float>
  requires std::is_floating_point<Float>::value
  Foo (Float x) : type_(float_like)  
  { 
    std::cout << "float like: " << x << std::endl; 
  }

};

int main () {
  Foo (1);
  Foo (5.1);
  return 1;
}

