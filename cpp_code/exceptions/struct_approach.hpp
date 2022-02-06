#include <utility>

#if 1

template<bool... Args> struct all_true;

template<> struct all_true<> {
  static constexpr bool value = true;
};

template<bool Arg, bool... Rest> 
struct all_true<Arg, Rest...> {
  static constexpr bool value = Arg && all_true<Rest...>::value;
};

#else

template<bool... Args>
using all_true = std::integral_constant<bool, (Args && ... && true)>;

#endif