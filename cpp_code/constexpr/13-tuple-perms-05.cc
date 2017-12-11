#include <iostream>
#include <tuple>
#include <utility>

using std::cout;
using std::decay_t;
using std::endl;
using std::forward;
using std::get;
using std::index_sequence;
using std::make_index_sequence;
using std::make_tuple;
using std::ostream;
using std::size_t;
using std::tuple;
using std::tuple_cat;
using std::tuple_size;
using std::void_t;

template<typename Tuple, size_t... Is>
void 
print_tuple_impl(ostream& os, Tuple &&t, index_sequence<Is...>) 
{
  ((os << (Is == 0 ? "" : ", ") << get<Is>(forward<Tuple>(t))), ...);
}

template<typename Tuple, typename = void_t<decltype(get<0>(Tuple{}))>>
decltype(auto) operator<<(ostream& os, Tuple &&t)
{
  constexpr size_t sz = tuple_size<decay_t<Tuple>>::value;
  os << "(";
  print_tuple_impl(os, forward<Tuple>(t), make_index_sequence<sz>{});
  return os << ")";
}

template<size_t start, typename Tuple, size_t... Is>
constexpr auto subtuple_impl(Tuple &&t, index_sequence<Is...>) {
  return make_tuple(get<Is + start>(forward<Tuple>(t))...);
}

template<size_t start, size_t finish, typename Tuple>
constexpr auto subtuple(Tuple&& t) {
  static_assert(start <= finish);
  constexpr size_t sz = finish - start;
  return subtuple_impl<start>(forward<Tuple>(t), make_index_sequence<sz>{});
}

template<size_t rotval, typename Tuple>
constexpr auto rotate_r (Tuple &&t) {
  constexpr size_t sz = tuple_size<decay_t<Tuple>>::value;
  constexpr size_t fh_size = sz - (rotval % sz);
  auto first_half = subtuple<0, fh_size>(forward<Tuple>(t));
  auto second_half = subtuple<fh_size, sz>(forward<Tuple>(t));
  return tuple_cat(second_half, first_half);
}

template<size_t rotval, typename Tuple>
constexpr auto rotate_l (Tuple &&t) {
  constexpr size_t sz = tuple_size<decay_t<Tuple>>::value;
  return rotate_r<sz - (rotval % sz)>(forward<Tuple>(t));
}

template<typename Tuple>
constexpr auto tuple_tail(Tuple &&t) {
  constexpr size_t sz = tuple_size<decay_t<Tuple>>::value;
  return subtuple<1, sz>(forward<Tuple>(t));
}

template<size_t Nx, size_t Mx, typename Tuple>
constexpr auto swap_elts (Tuple &&t) {
  constexpr size_t sz = tuple_size<decay_t<Tuple>>::value;
  if constexpr (Nx == Mx) return t;
  constexpr size_t Ny = Nx % sz;
  constexpr size_t My = Mx % sz;
  constexpr size_t N = (Ny > My) ? My : Ny;
  constexpr size_t M = (Ny > My) ? Ny : My;

  // now N < M, N < sz, M < sz

  auto&& nth = make_tuple(get<N>(forward<Tuple>(t)));
  auto&& mth = make_tuple(get<M>(forward<Tuple>(t)));
  auto&& tmp1 = tuple_cat(mth, tuple_tail(rotate_l<N>(forward<Tuple>(t))));
  auto&& tmp2 = tuple_cat(nth, tuple_tail(rotate_l<M-N>(tmp1)));
  return rotate_r<M>(tmp2);
}

template<typename Tuple, size_t... Is>
void
print_rotates(Tuple &&t, index_sequence<Is...>) {  
  cout << "Left rotations: " << endl;
  ((cout << Is << ": " << rotate_l<Is>(forward<Tuple>(t)) << endl), ...);
}

int
main () {
  constexpr auto test = make_tuple(1, 1.5, 2, 2.5, 3, 3.5);
  cout << "Simple: " << test << endl;
  constexpr auto subtest = subtuple<1, 4>(test);
  cout << "Subtuple: " << subtest << endl;
  constexpr auto testrot3 = rotate_r<3>(test);
  cout << "Rotated right by 3: " << testrot3 << endl;
  print_rotates(test, make_index_sequence<10>{});
  constexpr auto testswap24 = swap_elts<2, 4>(test);
  cout << "Swapped #2 and #4: " << testswap24 << endl;
}

