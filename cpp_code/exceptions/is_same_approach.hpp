#include <utility>

using std::is_same;

template<bool...>
struct all_helper {};

template<bool... Args>
using all_true = is_same<all_helper<true, Args...>, all_helper<Args..., true>>;

