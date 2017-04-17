#include <iostream>
#include <utility>

using std::boolalpha;
using std::cout;
using std::enable_if_t;
using std::endl;
using std::declval;
using std::false_type;
using std::is_reference;
using std::true_type;
using std::void_t;

template <typename T>
using dep_foobar = decltype(declval<T>().foobar());

template <typename T>
using foobarf = decltype(float{declval<T>().foobar()});

template <typename T>
using not_a_ref = enable_if_t <!is_reference<T>::value, T>;

template <typename, typename = void_t<>> struct has_typedef_foobar : false_type { };

template <typename T> 
struct has_typedef_foobar <T, 
                           void_t<foobarf<T>, not_a_ref<dep_foobar<T>> >> : true_type { };

struct foo { typedef float foobar; };
struct bar { };
struct buz { float foobar(); };
struct buzz { int foobar(); };
struct buzzz { float& foobar(); };

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

