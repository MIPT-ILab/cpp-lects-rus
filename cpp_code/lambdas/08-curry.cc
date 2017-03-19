#include <iostream>

using std::cout;
using std::endl;

template <typename Function, typename... Arguments>
auto curry(Function function, Arguments... args) 
{
  return [=](auto... rest) { 
    return function(args..., rest...); 
  };
}

int main ()
{
  auto fam = [](auto x, auto y, auto z) { return x * (y + z); };
  auto fam3 = curry(fam, 3); // 3 * (y + z)
  auto fa2m3 = curry(fam, 3, 2); // 3 * (2 + z)
  cout << fam (3, 2, 4) << endl;
  cout << fam3 (2, 4) << endl;
  cout << fa2m3 (4) << endl;
}

