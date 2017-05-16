#include <utility>

using std::integral_constant;

template <bool Arg> struct nx_helper {
  constexpr explicit nx_helper() noexcept(Arg) {}
};

template <typename ...T> void nx_join(T const&...) noexcept;

template <bool ...Args> struct all_true : 
  integral_constant<bool, noexcept(nx_join(nx_helper<Args>{}...))> {};
