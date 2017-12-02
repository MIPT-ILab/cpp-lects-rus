#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::endl;

template <size_t N, typename T, size_t Size>
constexpr array <T, N * Size>
cycle_elems (array <T, Size> a) {
  array <T, N * Size> result {};
  for (T i = 0; i < N * Size ; ++i)
    result[i] = a[i % Size];
  return result;
}

int
main ()
{
  constexpr array<size_t, 5> arr = {0, 4, 2, 1, 3};
  constexpr size_t third = arr[3] + arr[4];
  cout << third << endl;
  constexpr auto cycled = cycle_elems<3>(arr);
  for (auto s : cycled)
    cout << s << endl;
}

