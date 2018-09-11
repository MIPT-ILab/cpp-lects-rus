#include <iostream>

using std::cout;
using std::endl;

template <typename T> 
const T& min(const T& a, const T& b) { 
  return a < b ? a : b;
}

double min(double a, double b) {
  return a < b ? a : b;
}

template <typename T> 
const T& min(const T& a, const T &b, const T &c) {
  return min(min(a,b), c);
}

int main() {
  double a = 1.0, b = 2.0, c = 3.0;
  double m = min(a, b, c);
  cout << m << endl;
}