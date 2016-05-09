#include <cstdint>

using std::size_t;

template <typename T>
concept bool Sequence() {
  return 
    requires { typename T::element_type; } &&
    requires (T t, typename T::element_type x) {
      { t.size() } -> size_t;
      { t.empty() } -> bool;
      { t.back() } -> typename T::element_type;
      { t.push_back(x) } // not specified (!)
    };
}

template <typename T> 
requires Sequence<T>()
void fill_with_random (T &x, int n);

