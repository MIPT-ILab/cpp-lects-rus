#include <iostream>

int main() {
  for (int i = 0; i < 10; ++i)
    std::cout << 1'000'000'000 * i << std::endl;
}