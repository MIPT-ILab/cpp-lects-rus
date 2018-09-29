#include <iostream>

using std::cout;
using std::endl;

template <typename T> struct D;

template <> struct D<void> {
  enum { max = 100 };
};

void clear(char *buf) {
  cout << "cleaning up " << D<void>::max << endl;
  for (int k = 0; k < D<void>::max; ++k)
    buf[k] = 0;
}