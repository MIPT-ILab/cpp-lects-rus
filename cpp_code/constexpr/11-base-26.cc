#include <iostream>

using std::cout;
using std::endl;

typedef unsigned long long ull;

constexpr ull base26(char const *s, ull ps) {
  return (*s && !(*s >= 'a' && *s <= 'z')) ? throw "bad char!" :
    (!*s ? ps : base26(s + 1, (ps * 26ULL) + (*s - 'a')));
}

constexpr ull operator "" _26(char const *s, std::size_t len) {
  return base26(s, 0);
}

int
main ()
{
  cout << "bcd"_26  << endl;
}

