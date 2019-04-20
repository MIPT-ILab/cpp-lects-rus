#include <algorithm>
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::find_if;
using std::pair;

class ct_string {
  char const *s_;
  size_t len_;
public:
  template <size_t N> constexpr ct_string(char const (&s)[N]): s_(s), len_(N) {} 
  constexpr bool operator==(ct_string rhs);
};

constexpr bool ct_string::operator==(ct_string rhs) {
  if (len_ != rhs.len_)
    return false;
  for (size_t i = 0; i != len_; ++i) 
    if (s_[i] != rhs.s_[i])
      return false;
  return true;
}

constexpr pair<ct_string, int> ct_map[] = {{"one", 1}, {"two", 2}, {"three", 3}};

template <typename P, size_t N>
auto constexpr access(P const (&a)[N], typename P::first_type k) {
  size_t i = 0; 
  for (; i < N; ++i)
    if (k == a[i].first)
      return a[i].second;
  if (i == N)
    throw "not found";
}

int
main () {
  constexpr int result = access(ct_map, "three");
  cout << result << endl;
}
