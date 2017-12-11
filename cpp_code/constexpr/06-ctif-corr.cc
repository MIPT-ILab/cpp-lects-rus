#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::is_integral;
using std::string;

template<typename T>
auto length(T value) {
  if constexpr (is_integral<T>::value) 
    return sizeof(T);
  else
    return value.length();
}

int 
main() {
  int a = 5;
  string b = "foo";
  cout << length(a) << ' ' << length(b) << endl;
}

