#include <iostream>
#include <vector>

#include "myranges.hpp"

int main() {
  std::vector v = {0, 1, 2, 3, 4, 5, 6};
  auto is_even = [](auto &&i) {
    std::cout << "even: " << i << std::endl;
    return ((i % 2) == 0);
  };
  auto square = [](auto &&i) {
    std::cout << "square: " << i << std::endl;
    return i * i;
  };

  for (auto &&i :
       v | ranges::views::filter(is_even) | ranges::views::transform(square))
    std::cout << "number: " << i << std::endl;

  for (auto &&i :
       v | ranges::views::transform(square) | ranges::views::filter(is_even))
    std::cout << "number: " << i << std::endl;
}