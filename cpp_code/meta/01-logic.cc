#include <cassert>
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::false_type;
using std::true_type;

namespace MyLogic {

template<typename T, typename U> struct is_same : false_type {}; 
template<typename T> struct is_same<T, T> : true_type {};
template<typename T, typename U> bool is_same_v = is_same<T, U>::value;
template<typename T, typename U> 
using is_same_t = typename is_same<T, U>::type; 

template <typename T, typename U> struct and_ : false_type {};
template <> struct and_<true_type, true_type> : true_type {};
template <typename T, typename U> bool and_v = and_<T, U>::value; 
template<typename T, typename U> 
using and_t = typename and_<T, U>::type; 

template <typename T> struct not_ : false_type {}; 
template <> struct not_<false_type> : true_type {};
template <typename T> bool not_v = not_<T>::value; 
template<typename T> 
using not_t = typename not_<T>::type;

int
check ()
{
  cout << (is_same<int, int>::value && !is_same<char, int>::value) << endl;
  cout << (is_same_v<int, int> && !is_same_v<char, int>) << endl;
  cout << (and_v<is_same_t<int, int>, not_t<is_same_t<char, int>>>) << endl;
  cout << (and_v<is_same<int, int>, not_<is_same<char, int>>>) << endl;
}

}

int
main () {
  MyLogic::check();
}

