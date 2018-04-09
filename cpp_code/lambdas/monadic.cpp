#include <utility>
#include <functional>
#include <iostream>

using namespace std;

auto List = [](auto ... xs) {
    return [=](auto access) { return access(xs...); };
};

auto head = [](auto xs) {
    return xs([](auto first, auto ... rest) { return first; });
};

auto tail = [](auto xs) {
    return xs([](auto first, auto ... rest) { return List(rest...); });
};

auto length = [](auto xs) {
//    cout << typeid(xs).name() << endl;
    return xs([](auto ... z) { return sizeof...(z); });
};

auto fmap = [](auto func) {
    return [func] (auto alist) {
      return alist(
        [func](auto ... xs)
          { 
            return List(func(xs)...); 
          }
      );
    };
  };

auto concat = [](auto l1, auto l2) {
    auto access1 = [=](auto ... p) {
      auto access2 = [=](auto ... q) {
        return List(p..., q...);
      };
      return l2(access2);
    };
    return l1(access1);
};

template <class Func>
auto flatten(Func)
{
  return List(); 
}
 
template <typename Func, typename A, typename ... B>
auto flatten(Func f, A a, B... b)
{
  return concat(f(a), flatten(f, b...));
}

auto flatmap = [](auto func) {
   return [func](auto alist) {
       return alist([func](auto... xs) { return flatten(func, xs...);  });
   };
};

template <typename LIST, typename Func>
auto operator > (LIST l, Func f)
{
  return fmap(f)(l);   
}
 
template <typename LIST, typename Func>
auto operator >= (LIST l, Func f)
{
  return flatmap(f)(l);   
}

int
main (void)
{
// (1)
  auto lst = List(1, 'x', "Hello");
  auto three = length(lst); 
  cout << three << endl;
  cout << head(lst) << endl;
  cout << head(tail(lst)) << endl;
  cout << head(tail(tail(lst))) << endl;
// (2)
  auto twice = [](auto i) { return i*2; };
  auto display = [](auto i) { cerr << i << " "; return i; };
  auto l1 = List(1, 2, 3, 4);
  auto l2 = fmap(twice)(l1);
  cout << head (l2) << endl;
  auto l3 = fmap(display)(l2); 
  cerr << endl;
// (3)
  auto pair = [](auto i) { return List(-i, i); };
  auto count = [](auto... a) { return List(sizeof...(a)); };
  auto l4 = List(1, 2, 3);
  auto l5 = flatmap(pair)(l4);
  auto l6 = fmap(display)(l5); 
  cerr << endl;
// (4)
  auto l7 = 
     List(1, 2, 3) >= pair > display;
  cerr << endl;
}

