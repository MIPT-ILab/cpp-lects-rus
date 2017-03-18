#include <cstdio>

using std::puts;

auto main () -> int 
{ 
  auto func = [] { puts ("Hello!\n"); return 0; };
  return func();
}

