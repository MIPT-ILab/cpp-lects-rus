#include <iostream>

using namespace std;

template <typename T = int>
class X {
public:
  X() { cout << "T size is " << sizeof(T) << endl; }
};

int
main (void) {
  X<> t;
}

