#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "myranges.hpp"

int main() {
 std::string input = " 1a2a3Z4b5Z6cz ";
  std::string result = input
                     | ranges::views::filter(::isalpha)
                     | ranges::views::transform(::tolower)
                     | ranges::to<std::string>
                     | ranges::action::sort
                     | ranges::action::unique;
  std::cout << result << std::endl;
}