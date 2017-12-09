#include <iostream>
#include <tuple>
#include <utility>

using std::ostream;
using std::cout;
using std::get;
using std::endl;
using std::forward;
using std::index_sequence;
using std::index_sequence_for;
using std::make_index_sequence;
using std::make_tuple;
using std::size_t;
using std::tuple;
using std::tuple_cat;
using std::tuple_size;

template<typename Tuple, size_t... Is>
void 
print_tuple_impl(ostream& os, const Tuple &t, index_sequence<Is...>) 
{
  ((os << (Is == 0 ? "" : ", ") << get<Is>(t)), ...);
}
 
template<typename... Args>
decltype(auto) operator<<(ostream& os, const tuple<Args...>& t)
{
    os << "(";
    print_tuple_impl(os, t, index_sequence_for<Args...>{});
    return os << ")";
}

template<size_t start, typename Tuple, size_t... Is>
constexpr auto subtuple(const Tuple &t, index_sequence<Is...>) {
  return make_tuple(get<Is + start>(t)...);
}

template<size_t rotval, typename... Args>
constexpr auto rotate_r (const tuple<Args...>& t) {
  constexpr size_t fh_size = sizeof...(Args) - (rotval % sizeof...(Args));
  constexpr size_t sh_size = sizeof...(Args) - fh_size;
  auto first_half = subtuple<0>(t, make_index_sequence<fh_size>{});
  auto second_half = subtuple<fh_size>(t, make_index_sequence<sh_size>{});
  return tuple_cat(second_half, first_half);
}

template<size_t rotval, typename... Args>
constexpr auto rotate_l (const tuple<Args...>& t) {
  return rotate_r<(sizeof...(Args) - (rotval % sizeof...(Args)))>(t);
}

template<size_t Nx, size_t Mx, typename... Args>
constexpr auto swap_elts (const tuple<Args...>& t) {
  if constexpr (Nx == Mx) return t;
  constexpr size_t Ny = Nx % sizeof...(Args);
  constexpr size_t My = Mx % sizeof...(Args);
  constexpr size_t N = (Ny > My) ? My : Ny;
  constexpr size_t M = (Ny > My) ? Ny : My;

  // now N < M, N < sizeof...(Args), M < sizeof...(Args)

  auto nth = get<N>(t);
  auto mth = get<M>(t);
  auto tN = rotate_l<N>(t);
  auto tmp1 = tuple_cat(make_tuple(mth), subtuple<1>(tN, make_index_sequence<sizeof...(Args) - 1>{}));
  auto tM = rotate_l<M-N>(tmp1);
  auto tmp2 = tuple_cat(make_tuple(nth), subtuple<1>(tM, make_index_sequence<sizeof...(Args) - 1>{}));
  return rotate_r<M>(tmp2);
}

// based on observation, that:
// (x1, x2, x3, x4, ...) = (x1, x2) * (x1, x3, x4, ...)
template<size_t I, size_t J, size_t... Is, typename Tuple>
constexpr auto permute_elts (const Tuple& t) {
  if constexpr(sizeof...(Is) > 0) {
    return permute_elts<I, Is...>(swap_elts<I, J>(t));
  }
  else
    return swap_elts<I, J>(t);
}

template<typename Tuple, size_t... Is>
void
print_rotates(const Tuple &t, index_sequence<Is...>) {  
  cout << "Rotate test: " << endl;
  ((cout << Is << ": " << rotate_l<Is>(t) << endl), ...);
}

int
main () {
  constexpr auto test1 = make_tuple(1, 1.5, 2, 2.5, 3, 3.5);
  cout << "Simple: " << test1 << endl;
  constexpr auto test1rot3 = rotate_r<3>(test1);
  cout << "Rotated right by 3: " << test1rot3 << endl;
#if 0
  print_rotates(test1, make_index_sequence<10>{});
#endif
  constexpr auto test1swap24 = swap_elts<2, 4>(test1);
  cout << "Swapped #2 and #4: " << test1swap24 << endl;
  constexpr auto test1perm23140 = permute_elts<2, 3, 1, 4, 0>(test1);
  cout << "After (2 3 1 4 0) permutation: " << test1perm23140 << endl;
}

