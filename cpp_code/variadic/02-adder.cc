#include <iostream>

using std::cout;
using std::endl;

template <typename T> T add(T v) { return v; }

template <typename T, typename... Args>
add (T first, Args... args) {
  return first + add (args...);
}

int main ()
{
  int t = add (1, 1.0, 1u);
  cout << t << endl;
}

