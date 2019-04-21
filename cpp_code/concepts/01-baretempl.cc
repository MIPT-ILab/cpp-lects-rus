#include <string>
#include <vector>

template<typename R, typename T>
bool contains (R const& range, T const& value) {
  for (auto const& x : range)
    if (x == value)
      return true;
  return false;
}

int main () {
  std::vector<std::string> v {"0", "1", "2"};
  bool is_in = contains(v, 1); 
}