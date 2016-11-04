#include <iostream>

using namespace std;

struct Costly {
  Costly () { cout << "ctor" << endl; }
  Costly (const Costly&) { cout << "copy" << endl; }
  Costly& operator= (const Costly&) { cout << "assign" << endl; return *this; }

  Costly (Costly&&) { cout << "move ctor" << endl; }
  Costly& operator= (const Costly&&) { cout << "move" << endl; return *this; }
};

Costly foo (Costly x) { return x; }

//void bar (Costly &c) { (void) c; }

#if 0
template <typename Fun, typename Arg>
decltype(auto)
transparent (Fun fun, Arg &arg) 
  { return fun(arg); }


template <typename Fun, typename Arg>
decltype(auto)
transparent (Fun fun, const Arg &arg)
  { return fun(arg); }
#endif

#if 1
template <typename Fun, typename Arg>
decltype(auto)
transparent (Fun fun, Arg &&arg)
  { return fun (arg); }
#endif


#if 0
template <typename Fun, typename Arg>
decltype(auto)
transparent (Fun fun, Arg &&arg)
  { return fun (forward<Arg>(arg)); }
#endif

void g(int &&t) { cout << "rvalue" << endl; }
void g(int &t) { cout << "lvalue" << endl; }

template <typename T> void 
h(T &&t) { g(std::forward<T>(t)); }


int main (void)
{
  Costly b;
  cout << 1 << endl;
  Costly t = transparent (&foo, b);
  cout << 2 << endl;
  Costly s = transparent (&foo, foo(b));

  cout << "twobound:" << endl;
  int x = 1;
  const int cx = 1;
  h (1);
  h (x);
  // h (move(cx));
}

