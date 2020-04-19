#include <iostream>
#include <vector>

#include "myranges.hpp"

int main() {
  std::vector v = {0, 1, 2, 3, 4, 5, 6};
  auto is_even = [](auto&& i) { return ((i % 2) == 0); };
  
  // 1. filter_view, Concept assertion failed : viewable_range<BaseRng>
#if 0
  for (int i : ranges::filter_view(v, is_even))
    std::cout << i << " ";
  std::cout << std::endl;
#endif  
  
  // 2. explicit filter
  for (int i : ranges::views::filter(v, is_even)) // why {is_even} not working?
    std::cout << i << " ";
  std::cout << std::endl;

  // 3. pipeline
  for (int i : v | ranges::views::filter(is_even)) // why {is_even} not working?
    std::cout << i << " ";
  std::cout << std::endl;
  
  auto f1 = ranges::views::filter(v, is_even);
  auto f2 = v | ranges::views::filter(is_even);
  if (ranges::equal(f1, f2))
    std::cout << "equal!" << std::endl;
}