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

int
main () {
  constexpr auto test = make_tuple(1, 1.5, 2, 2.5, 3, 3.5);
  cout << "Simple: " << test << endl;
}

