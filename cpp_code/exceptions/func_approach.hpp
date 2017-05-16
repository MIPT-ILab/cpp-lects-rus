#include <utility>

using std::integral_constant;

constexpr bool all_truef() { return true; }

template<typename Arg, typename... Rest>
constexpr bool all_truef(Arg arg, Rest... rest) {
  return arg && all_truef(rest...);
};

template<bool... Args>
using all_true = integral_constant<bool, all_truef(Args...)>;

