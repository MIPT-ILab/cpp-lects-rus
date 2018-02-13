#include <iostream>

using std::cout;
using std::endl;

struct Base { 
  virtual ~Base(){ cout << "~Base" << endl; }
};

struct Derived: Base {
  ~Derived(){ cout << "~Derived" << endl; }
};

int
main ()
{
  try {
    throw Derived();
  }
#ifdef CORR
  catch (Base &b) {
  }
#endif
#if !defined(SLICE) && !defined(CORR)
  catch (Derived d) {
  }
#endif
#ifndef CORR
  catch (Base b) {
  }
#endif
}
