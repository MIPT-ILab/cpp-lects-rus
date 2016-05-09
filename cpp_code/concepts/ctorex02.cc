#include <utility>
#include <iostream>

struct Foo {

  enum {int_like, float_like} type_;

  template <int> struct dummy { dummy(int) {} };

  template <typename Int, 
            typename = std::enable_if<std::is_integral<Int>::value>>
  Foo (Int x, dummy<0> = 0) : type_(int_like) 
  { 
    std::cout << "int like: " << x << std::endl; 
  }

  template <typename Float, 
            typename = std::enable_if<std::is_floating_point<Float>::value>>
  Foo (Float x, dummy<1> = 0) : type_(float_like)  
  { 
    std::cout << "float like: " << x << std::endl; 
  }

};

int main () {
  Foo (1);
  Foo (5.1);
  return 1;
}

