#include <utility>

template <typename T> struct TD;

void foo(int x) {
  int y, z;
  decltype(x) t1; // id-expr -> int
  decltype(x ? y : z) t2 = y; // lvalue expr -> int&
  decltype(std::move(x)) t3 = 1; // xvalue expr -> int&&
  decltype(x + 0) t4; // prvalue expr -> int

  TD<decltype(t1)> d1;
  TD<decltype(t2)> d2;
  TD<decltype(t3)> d3;
  TD<decltype(t4)> d4;
}

