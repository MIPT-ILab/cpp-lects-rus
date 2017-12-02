#include <algorithm>
#include <iostream>
#include <string_view>
#include <utility>

using std::cout;
using std::endl;
using std::find_if;
using std::string_view;
using std::pair;

constexpr pair<string_view, int> ct_map[] = {{"one", 1}, {"two", 2}, {"three", 3}};

#if 0
template <typename T>
struct matcher1st {
  T d_value;
  template <typename P>
  constexpr bool operator()(P const& p) const {
    return this->d_value == p.first;
  }
};

template <typename T>
constexpr matcher1st<T> match1st(T value) {
  return matcher1st<T>{ value };
}

template <typename P, size_t N, typename K>
auto constexpr access(P const (&a)[N], K k) {
  P const* it = find_if(begin(a), end(a), match1st(k));
  return it == end(a) ? throw "not found" : it->second;
}
#endif

int
main () {
#if 0
  int result = access(ct_map, string_view("three"));
  cout << result << endl;
#endif
}
