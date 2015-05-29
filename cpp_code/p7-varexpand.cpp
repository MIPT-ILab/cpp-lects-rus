#include <utility>
#include <functional>
#include <iostream>

using namespace std;

template <typename T> decltype (auto) foo (T x)
{
  cout << x << endl;
  return;
}

template <class... T>
void lvisualize01(T... args)
{
  int x[] {0, (foo(args), 0)... };
}

template <class... T>
void lvisualize02(T... args)
{
  using expand_type = int[];
  expand_type {(foo(args), void(), 0)... };
  /* leading 0 for void parameter packs
     uses braced-init-list initialization rules
     void() is to prevent malicious "operator," overloads, which
     cannot exist for void types */
}

struct expand_type 
{
  template <typename... T> expand_type(T&&...) {}
};

template <class... T>
void lvisualize(T... args)
{
  expand_type {(foo(args),0)... };
}

auto main () -> int
{
  std::cout << "range-for over brace-init-list: \n";
  for(int x : {-1, -2, -3}) // the rule for auto makes this ranged for work
      std::cout << x << ' ';
  std::cout << '\n';

  lvisualize01 ();
  lvisualize01 (1, '2', 3.0, "Hello");
  lvisualize02 ();
  lvisualize02 (1, '2', 3.0, "Hello");
  lvisualize ();
  lvisualize (1, '2', 3.0, "Hello");
  return 0;
}

