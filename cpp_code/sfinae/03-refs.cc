#include <iostream>

using std::cout;
using std::endl;

template <int & Ref> 
struct SomeThing 
{ 
  void dump() { cout << Ref << endl; }
};

int global = 14;

int main () {
  int ptr = 42;
  // SomeThing<ptr> s;
  SomeThing<global> g;
  g.dump();
}

