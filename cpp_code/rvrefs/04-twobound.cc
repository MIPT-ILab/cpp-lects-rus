#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::forward;

void g(int &&t) { cout << "rvalue" << endl; }
void g(int &t) { cout << "lvalue" << endl; }

template <typename T> struct TD;

template <typename T> void 
h(T &&t) {
#ifdef DEBUG
  TD<T> td1;
  TD<decltype(t)> td2;
  TD<decltype(forward<T>(t))> td3; 
#endif
  g(forward<T>(t));
}

int main (void)
{
  cout << "twobound:" << endl;
  h (1);
  int x = 1;
  h (x);
#if defined(CONST)
  const int cx = 1;
  h (cx);
#endif
}

