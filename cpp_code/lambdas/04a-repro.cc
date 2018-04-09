#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::forward;
using std::move;

using Heavy = int;

int foo (Heavy& h) { return 1; }
int bar (Heavy&& h) { return 2; }

int
main ()
{
  auto transparent = [](auto f, auto&&... param) { 
    return f(forward<decltype(param)>(param)...);
  };
  Heavy a;
  transparent (foo, a);
  transparent (bar, std::move(a));
}

