#include <cassert>
#include <iostream>
#include <vector>

#include "comb.hpp"

int main() {
  int n = 5;
  int t = 3;

  std::cout << "first pass" << std::endl;
  all_comb ac(n, t);
  do {
    for (auto it = ac.begin(); it != ac.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;
  } while (ac.next_comb());

  std::cout << "once again" << std::endl;
  do {
    for (auto it = ac.begin(); it != ac.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;
  } while (ac.next_comb());
}