#include <utility>
#include <iostream>

template <typename T>
concept bool Int = std::is_integral<T>::value;

template <typename T>
concept bool Float = std::is_floating_point<T>::value;


struct Foo {

  enum {int_like, float_like} type_;

  template <Int T> 
  Foo (T x) : type_(int_like) 
  { 
    std::cout << "int like: " << x << std::endl; 
  }

  template <Float T>
  Foo (T x) : type_(float_like)  
  { 
    std::cout << "float like: " << x << std::endl; 
  }

};

int main () {
  Foo (1);
  Foo (5.1);
  return 1;
}

