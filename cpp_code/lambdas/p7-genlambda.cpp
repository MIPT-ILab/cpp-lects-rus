#include <utility>
#include <iostream>

using namespace std;

auto list = [](auto ...xs) {
    return [=](auto access) { return access(xs...); };
};

auto head = [](auto xs) {
    return xs([](auto first, auto ...rest) { return first; });
};

auto tail = [](auto xs) {
    return xs([](auto first, auto ...rest) { return list(rest...); });
};

auto length = [](auto xs) {
    return xs([](auto ...z) { return sizeof...(z); });
};

int 
main (void)
{
  auto three = length(list(1, '2', "3")); 
  cout << "three: " << three << endl;
  return 0;
}

