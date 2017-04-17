#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::enable_if_t;
using std::false_type;
using std::true_type;

template<typename T, typename U> struct my_is_same : false_type {};
template<typename T> struct my_is_same<T, T> : true_type {};

template <typename T>
enable_if_t<my_is_same<T, int>::value, void>
foo (T x) {
   cout << "forint" << endl;
}

template <typename T>
enable_if_t<!my_is_same<T, int>::value, void>
foo (T x) {
   cout << "forall" << endl;
}

int
main ()
{
  foo (1);
  foo (1.0);
}

