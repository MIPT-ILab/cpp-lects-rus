#include <iostream>

using std::cout;
using std::endl;

class ct_string {
  char const *s_;
  size_t len_;
public:
  template <size_t N> constexpr ct_string(char const (&s)[N]): s_(s), len_(N) {} 
  constexpr ct_string(char const *s) : s_(s), len_(0) {
    while (*s++ != '\0') len_ += 1;
  }
  constexpr ct_string() : s_(nullptr), len_(0) {}
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

template <typename F, typename S, size_t N>
struct ctmap {
  struct {
    F first = F{}; 
    S second = S{};
  } map_[N];

  template<typename T, typename U, typename ... Ts>
  constexpr void fill_map(int k, T x, U y, Ts ... ts) {
    map_[k].first = F(x); 
    map_[k].second = S(y);
    if constexpr (sizeof...(Ts) != 0) {
      fill_map(k + 1, ts...);
    }
  }

  template<typename ... T>
  constexpr ctmap(T ... ts) {
    fill_map(0, ts...);
  }

  constexpr S operator[](F k) const { 
    for (size_t i = 0; i < N; ++i)
      if (k == map_[i].first)
        return map_[i].second;
  }
};

constexpr ctmap<ct_string, int, 3> ct_map("one", 1, "two", 2, "three", 3);

int
main () {
  constexpr int result = ct_map["three"];
  cout << result << endl;
}
