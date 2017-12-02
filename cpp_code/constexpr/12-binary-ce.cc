#include <iostream>

using std::cout;
using std::endl;

template<typename ... Ts>
constexpr unsigned long long binparser (unsigned long long accum, char c, Ts ... cs) {
  unsigned digit = (c == '1') ? 1 : (c == '0') ? 0 : throw "out of range"; 
  accum = accum * 2 + digit;
  if constexpr (sizeof...(Ts) != 0)
    return binparser(accum, cs...);
  return accum;
}

template<char ... Chars>
constexpr unsigned long long operator "" _binary() {
  return binparser (0ull, Chars...); 
}

int
main ()
{
  cout << 1010101010101_binary  << endl;
}

