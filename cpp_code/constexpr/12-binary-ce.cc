#include <array>
#include <iostream>

using std::cout;
using std::endl;

template<typename ... Ts>
constexpr unsigned long long binparser (unsigned long long accum, Ts ... cs) {  
  std::array tmp{cs...};
  for (auto&& c : tmp) {
    unsigned digit = (c == '1') ? 1 : (c == '0') ? 0 : throw "out of range"; 
    accum = accum * 2 + digit;
  }
  return accum;
}

template<char ... Chars> // '1', '0', '1', .... , '1'
constexpr unsigned long long operator "" _binary() {
  return binparser (0ull, Chars...); 
}

int
main ()
{
  cout << 1010101010101_binary  << endl;
}

