#ifndef CONCRETE_GUARD_
#define CONCRETE_GUARD_

#include <iostream>

using std::cout;
using std::endl;

static inline int 
f(int x) {
  cout << "f(1): " << x << endl;
  return x;
}

static inline int 
f(int x, int y) {
  cout << "f(2): " << x << " " << y << endl;
  return x+y;
}

static inline int 
f(int x, int y, int z) {
  cout << "f(3): " << x << " " << y << " " << z << endl;
  return x+y+z;
}

static inline int 
f(int x, int y, int z, int w) {
  cout << "f(4): " << x << " " << y << " " << z << " " << w << endl;
  return x+y+z+w;
}

static inline int 
h(int x) {
  cout << "h(1): " << x << endl;
  return x;
}

static inline int 
h(int x, int y) {
  cout << "h(2): " << x << " " << y << endl;
  return x+y;
}

static inline int 
h(int x, int y, int z) {
  cout << "h(3): " << x << " " << y << " " << z << endl;
  return x+y+z;
}

static inline int 
h(int x, int y, int z, int w) {
  cout << "h(4): " << x << " " << y << " " << z << " " << w << endl;
  return x+y+z+w;
}

#endif