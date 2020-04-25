#include <iostream>
#include <string>
#include <string_view>
#include <utility>

template <typename P, size_t N>
auto constexpr access(P const (&a)[N], typename P::first_type k) {
  size_t i = 0; 
  for (; i < N; ++i)
    if (k == a[i].first)
      return a[i].second;
  if (i == N)
    throw "not found";
}

int main() {
  constexpr std::pair<std::string_view, int> ct_map[] = {{"one", 1}, {"two", 2}, {"three", 3}};
  constexpr int result = access(ct_map, "three");
  std::cout << result << std::endl;
}
