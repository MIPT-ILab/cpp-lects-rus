#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::move;
using std::forward;

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
  Costly b1, b2;
  cout << "Direct lval: " << endl;
  Costly t1 = foo(b1);
  cout << "Direct rval: " << endl;
  Costly t2 = foo(move(b1));
  cout << "Transparent lval: " << endl;
  Costly t3 = transparent (&foo, b2);
  cout << "Transparent rval:" << endl;
  Costly t4 = transparent (&foo, move(b2));
}

