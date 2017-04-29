#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::endl;

template <size_t N, size_t Size >
constexpr array <size_t, N * Size>
cycle_indices (array <size_t, Size> a) {
  array <size_t, N * Size> result {};
  for (size_t i = 0; i < N * Size ; ++i) {
    result[i] = i % Size ;
  }
  return result;
}

int
main ()
{
  constexpr array<size_t, 5> arr = {0, 1, 2, 3, 4};
  constexpr size_t third = arr[3] + arr[4];
  cout << third << endl;
  constexpr auto cycled = cycle_indices<3, 5>(arr);
  for (auto s : cycled)
    cout << s << endl;
}

