#include <iostream>

using std::cout;
using std::endl;

template <typename T> struct D {
  enum { max = 10 };
};

char buffer[D<void>::max];

extern void clear(char *buf);

int
main () {
  cout << "Requesting to clean " << D<void>::max << endl;
  clear(buffer);
}