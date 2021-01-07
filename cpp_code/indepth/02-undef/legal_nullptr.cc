#include <iostream>

struct Poly {
    virtual ~Poly() {}
};

int main() {
  try {
    int *pi = nullptr;
    std::cout << typeid(*pi).name() << std::endl; // this may be UB, but...
    Poly *p = nullptr;    
    std::cout << typeid(*p).name() << std::endl; // this is well-defined!
  }
  catch(const std::bad_typeid&) {
      std::cout << "bad typeid\n";
  }
}
