#include <stdio.h>

namespace N {
  struct A;
  template <typename T> int f(T*) { printf("Bingo\n"); }
}

N::A *a;

int main()
{
  int i = f<N::A>(a);
  return i;
}
