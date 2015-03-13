#include <iostream>
#include <utility>

template<typename T> void 
bar(T &&t)
{
  std::cout << "b: " << t << "\n";
}

/* recursion end */
void foo() {}

template<typename Arg, typename ... Args> void 
foo(Arg &&arg, Args &&... args)
{
    bar(std::forward<Arg>(arg));
    foo(std::forward<Args>(args)...);
}

int 
main()
{
  foo (1, 2, 3, "3");
  return 0;
}

