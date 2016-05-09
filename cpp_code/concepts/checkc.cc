#include <utility>
#include <iostream>

template <typename C>
concept bool Int = std::is_integral<C>::value;

void check (Int x) {
  std::cout << "Brief" << std::endl;
}

template <typename C> 
requires std::is_integral<C>::value
void check (C x) {
  std::cout << "Full" << std::endl;
}

int 
main (void) {
  check<Int> (1);
  return 0;
}
