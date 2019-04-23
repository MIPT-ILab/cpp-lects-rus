#include <iostream>
#include <utility>

template<bool b, bool ... bs>
concept bool AllTrueRec = b && (sizeof...(bs) == 0) ? true : AllTrueRec<bs...>;

template<bool b1, bool b2, bool b3>
requires AllTrueRec<b1, b2, b3>
void foo() {
}

template<bool ... bs>
concept bool AllTruePack = (bs && ... && true);

template<bool b1, bool b2, bool b3>
requires AllTruePack<b1, b2, b3>
void bar() {
}

int
main() {
  foo<true, true, true>();
  bar<true, true, true>();
}
