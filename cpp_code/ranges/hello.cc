#include <iostream>

#include "myranges.hpp"

int main() {
  std::string s{"hello"};
  ranges::for_each(s, [](char c) { std::cout << c; });
  std::cout << std::endl;
}
