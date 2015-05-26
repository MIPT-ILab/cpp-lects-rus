#include <iostream>
#include <utility>
#include <array>
#include <vector>

using namespace std;

template<typename T> void 
bar(T &&t)
{
  cout << "b: " << t << "\n";
}

/* recursion end */
void foo() {}

template<typename Arg, typename ... Args> void 
foo(Arg &&arg, Args &&... args)
{
    bar (forward<Arg> (arg));
    foo (forward<Args> (args)...);
}

template<class ... Args> void f(Args ... args)
{
  cout << sizeof ... (args) << endl;
}

template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
}

template<typename... Ts>
auto make_array(Ts&&... ts)
{
  // array <common_type_t<Ts...>, sizeof...(ts)> ret { forward<Ts>(ts)... };
  vector < common_type_t<Ts...> > ret { forward<Ts>(ts)... };
  return ret;
}

int 
main()
{
  foo (1, 2, 3, "3");
  f();
  f(1);
  f(2, 1.0);
  cout << adder (2, 3, 5) << endl;

  auto b = make_array(1, 2, 3);
  cout << b.size() << '\n';
  for (auto i : b)
    cout << i << ' ';

  cout << endl;

  return 0;
}

