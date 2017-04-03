#include <iostream>
#include <utility>

using std::boolalpha;
using std::cout;
using std::endl;
using std::declval;

template <typename T> 
struct has_typedef_foobar {
  typedef char yes[1];
  typedef char no[2];

  template <typename C> static auto test(void*) -> decltype(declval<C>().foobar(), void(), yes{});
  template <typename> static no& test(...);

  static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

struct foo { typedef float foobar; };
struct bar { };
struct buz { float foobar(); };
struct buzz { int foobar(); };
struct buzzz { void foobar(); };

int
main ()
{
  cout << boolalpha << has_typedef_foobar<foo>::value << " " 
                    << has_typedef_foobar<bar>::value << " " 
                    << has_typedef_foobar<buz>::value << " " 
                    << has_typedef_foobar<buzz>::value << " " 
                    << has_typedef_foobar<buzzz>::value << " " 
                    << endl;
}

