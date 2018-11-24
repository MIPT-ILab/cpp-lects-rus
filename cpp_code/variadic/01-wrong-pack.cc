#include <iostream>

using std::cout;
using std::endl;

int bar(int) {
  cout << "victory!" << endl;
}

template <typename ... T>
void foo(T ... ts) {
  bar(ts)...;
}

int main() {
  foo(42);
}