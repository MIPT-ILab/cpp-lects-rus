// Real mystic of this case: it kind of works on both gcc and clang O0

#include <iostream>

int main() {
  int a = 0;
  int *p = &a;
  { int x = 42; p = &x; } // p became invalid
  int t = *p; // UB as specified
  std::cout << t << std::endl;
}
