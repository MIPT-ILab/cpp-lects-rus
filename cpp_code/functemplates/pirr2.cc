#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

template <typename T> 
const T& min(const T& a, const T& b) { 
  cout << "byref" << endl;
  return a < b ? a : b;
}

const char* min(const char* a, const char * b) {
  cout << "byval" << endl;
  return strcmp(a, b) < 0 ? a : b;
}

template <typename T> 
const T& min(const T& a, const T &b, const T &c) {
  return min(min(a,b), c);
}

int main() {
  const char *a = "1.0", *b = "2.0", *c = "3.0";
  const char *m = min(a, b, c);
  cout << m << endl;
}
