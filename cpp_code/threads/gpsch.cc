#include <iostream>

class gpsch {
  int X_, a_, c_, m_;

public:
  gpsch(int X0, int a, int c, int m) : X_(X0), a_(a), c_(c), m_(m) {}
  int next() {
    X_ = (a_ * X_ + c_) % m_;
    return X_;
  }
};

int main() {
  gpsch g(7, 106, 1284, 6075);
  for (int i = 0; i < 500; ++i) {
    int j = g.next();
    std::cout << i << "\t" << j << std::endl;
  }
}
