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

#if defined(STAGE0)

template <typename Fun, typename Arg>
decltype(auto)
transparent (Fun fun, Arg arg) 
  { return fun(arg); }

#elif defined(STAGE1)

template <typename Fun, typename Arg>
decltype(auto)
transparent (Fun fun, Arg &&arg)
  { return fun (arg); }

#elif defined(STAGE2)

template <typename Fun, typename Arg>
decltype(auto)
transparent (Fun fun, Arg &&arg)
  { return fun (forward<Arg>(arg)); }

#else

#error "define STAGE0, STAGE1 or STAGE2"

#endif

int main (void)
{
  Costly b;
  cout << 1 << endl;
  Costly t = transparent (&foo, b);
  cout << 2 << endl;
  Costly s = transparent (&foo, foo(b));
}

