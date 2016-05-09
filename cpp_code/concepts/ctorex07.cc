#include <experimental/type_traits>
#include <utility>
#include <iostream>

using namespace std::experimental;

template <typename T>
concept bool Int = is_integral_v<T>;

template <typename T>
concept bool Float = is_floating_point_v<T>;


struct Foo {

  enum {int_like, float_like} type_;

  // Abbreviated syntax 

  Foo (Int x) : type_(int_like) 
  { 
    std::cout << "int like: " << x << std::endl; 
  }

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

