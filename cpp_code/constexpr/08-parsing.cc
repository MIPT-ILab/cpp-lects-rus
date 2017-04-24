#include <iostream>
#include <limits>

using std::cout;
using std::endl;

template <typename T = int>
constexpr T ct_trit(const char* t) {
  T x = 0;
  size_t b = 0;
  for (size_t i = 0; t[i] != '\0'; ++i) {
    // TODO: overflow
    switch (t[i]) {
      case '\'': break;
      case '0': x = (x*3); ++b; break;
      case '1': x = (x*3) + 1; ++b; break;
      case 'j': x = (x*3) - 1; ++b; break;
      default: throw "Only '0', '1', and ',' may be used";
    }
  }
  return x;
}

int
main ()
{
  constexpr int u = ct_trit<int>("10j");
  constexpr int v = ct_trit<int>("j01");
  cout << u << " : " << v << endl;
}

