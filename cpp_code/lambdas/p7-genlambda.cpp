#include <utility>
#include <iostream>

using namespace std;

auto list = [](auto ...xs) {
    return [=](auto access) { return access(xs...); };
};

auto head = [](auto xs) {
    return xs([](auto first, auto ...rest) { return first; });
};

auto tail = [](auto xs) {
    return xs([](auto first, auto ...rest) { return list(rest...); });
};

auto length = [](auto xs) {
    return xs([](auto ...z) { return sizeof...(z); });
};


void
f (int x)
{
  cout << "Bingo: " << x << endl;
}

auto forwardingLambda = [](auto&& param) { f(std::forward<decltype(param)>(param)); };

template <class... T>
void lvisualize(T... args)
{ 
#if 0
  using expand_variadic_pack  = int[];
  expand_variadic_pack {0, ((cout << args << endl), void(), 0)... };
#endif

#if 0
  auto a = {(cout << args << endl)... }; (void)a;
#endif

  int dummy[] = {0, (cout << args << endl, void(), 0)... };

  /* uses braced-init-list initialization rules, which evaluates
     the elements inside a braced-init-list IN ORDER, to repetetively
     execute a certain operation
     void() is to prevent malicious "operator," overloads, which
     cannot exist for void types */
}
 

int 
main (void)
{
  forwardingLambda (1);
  auto three = length(list(1, '2', "3")); 
  cout << "three: " << three << endl;
  lvisualize(10, 20.2, "asdf", true);
  return 0;
}

