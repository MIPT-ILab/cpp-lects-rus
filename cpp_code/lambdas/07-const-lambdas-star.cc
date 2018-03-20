#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::index_sequence;
using std::make_index_sequence;

template <char... c> struct String {
  static char const buffer[sizeof...(c)];
};

template <char ... c>
char const String<c...>::buffer[sizeof...(c)] = { c... };

template <typename F, size_t ... I>
constexpr auto string_builder(F f, index_sequence<I...>) {
  return String<f(I)...>{};
}

#define STRING_TYPE(x)                                    \
  string_builder([](size_t i) constexpr { return x[i]; }, \
                 make_index_sequence<sizeof(x)>{})

template <typename T> struct TD;

int
main () {
  auto n = STRING_TYPE("nonsense");
  cout << n.buffer << endl;
#ifdef SEETYPE
  TD<decltype(n)> t1;
#endif
}