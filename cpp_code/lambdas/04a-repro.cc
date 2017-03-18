#include <utility>

int foo (int&) { return 0; }
int bar (int&&) { return 0; }

int
main ()
{
  auto transparent = [](auto f, auto&& param) { 
    return f(std::forward<decltype(param)>(param));
  };
  int a = 5;
  transparent (foo, a);
  transparent (bar, std::move(a));
}

