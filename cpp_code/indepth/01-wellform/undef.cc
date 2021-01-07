#include <iostream>

int main() {
  unsigned char x = 12;
  { 
    unsigned char x = x;
    std::cout << x << std::endl;
  }
}
