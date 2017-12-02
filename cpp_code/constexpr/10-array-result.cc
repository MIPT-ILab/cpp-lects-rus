#include <iostream>

using std::cout;
using std::endl;

template <typename T, size_t N>
class array_result {
  constexpr static size_t size_ = N;
  T data_[N] {};
public:
  template <typename ... Ts> constexpr array_result (Ts ... ints) : data_ {ints ...} {}
  constexpr size_t size() const { return N; }
  constexpr T& operator[](size_t n) { return data_[n]; }
  using iterator = const T*;
  constexpr iterator begin() const { return data_; }
  constexpr iterator end() const { return data_ + N; }
};

template <size_t N, typename T, size_t Size>
constexpr array_result <T, N * Size>
cycle_elems (array_result <T, Size> a) {
  array_result <T, N * Size> result {};
  for (T i = 0; i < N * Size ; ++i)
    result[i] = a[i % Size];
  return result;
}


int
main ()
{
  constexpr array_result<int, 5> arr = {0, 4, 2, 1, 3};
  constexpr auto cycled = cycle_elems<3>(arr);
  for (auto s : cycled)
    cout << s << endl;
}

