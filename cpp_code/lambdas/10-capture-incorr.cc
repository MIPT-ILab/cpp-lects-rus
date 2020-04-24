#include <iostream>

int main() {
  int x = 5;
  [&captured = &x] () mutable { captured += 3; } (); 
  std::cout << x << std::endl;
}