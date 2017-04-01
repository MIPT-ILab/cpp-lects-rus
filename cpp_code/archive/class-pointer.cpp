#include <iostream>

struct MyClass {
   int DoIt(float a, int b) const {
     std::cout << "DoIt: " << a << " " << b << std::endl;
   }
   // ....
};

typedef int (MyClass::*constif_t)(float, int) const; 

int 
main (void) 
{
  constif_t ptr = &MyClass::DoIt;
  MyClass c;

  // actual call
  (c.*ptr)(1.0, 1);

  // pointer
  MyClass *d = &c;
  (d->*ptr)(2.0, 2);

  return 0;
}

