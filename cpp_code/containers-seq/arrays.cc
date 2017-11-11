#include <array>
#include <iostream>
#include <utility>

using std::array;
using std::cout;
using std::endl;
using std::move;

template <typename T> using c_array = T[];

struct Point { int x, y; };

template<typename T, size_t N, size_t... Indices>
constexpr auto make_array(T (&& src)[N], std::index_sequence<Indices...>) {
    return array<T, N>{{ move(src[Indices])... }};
}

template<typename T, size_t N>
constexpr auto make_array( T (&& src)[N]) {
    return make_array(move(src), std::make_index_sequence<N>{});
}

constexpr auto xs = make_array(c_array<Point>{{2,3}, {5,7}, {11,13}, {17,19}});

int
main ()
{
  for (auto&& p : xs)
    cout << p.x << " " << p.y << endl;
}


