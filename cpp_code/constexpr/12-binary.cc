#include <iostream>

using std::cout;
using std::endl;

template<unsigned long long Sum, char... Chars> struct binparser;

template<unsigned long long Sum, char... Rest>
struct binparser<Sum, '0', Rest...> {
  static const unsigned long long value = binparser<Sum*2, Rest...>::value;
};

template<unsigned long long Sum, char... Rest>
struct binparser<Sum, '1', Rest...> {
  static const unsigned long long value = binparser<Sum*2 + 1, Rest...>::value;
};

template<unsigned long long Sum>  struct binparser<Sum> {
  static const unsigned long long value = Sum;
};

template<char... Chars>
constexpr unsigned long long operator "" _binary() {
  return { binparser <0, Chars...>::value };
}

int
main ()
{
  cout << 1010101010101_binary  << endl;
}

