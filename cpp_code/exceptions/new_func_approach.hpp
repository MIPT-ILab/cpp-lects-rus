#include <array>
#include <utility>

template<bool... Ts>
constexpr bool all_truef() {
  std::array<bool, SZ> arr_{Ts...};
  for (auto x : arr_)
    if (x == false)
      return false;
  return true;
};

template<bool... Args>
using all_true = std::integral_constant<bool, all_truef<Args...>()>;

