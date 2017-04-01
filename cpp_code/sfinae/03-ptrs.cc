#include <iostream>

using std::cout;
using std::endl;

template <int * Ptr> 
struct SomeThing 
{ 
  void dump() { cout << *Ptr << endl; }
};

int global = 14;

int main () {
  int ptr = 42;
  // SomeThing<&ptr> s;
  SomeThing<&global> g;
  g.dump();
}

