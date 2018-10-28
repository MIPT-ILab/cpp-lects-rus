#include <iostream>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <cxxabi.h>

using std::cout;
using std::endl;
using std::string;

struct Empty {};

template <typename T> string type_name() {
  typedef typename std::remove_reference<T>::type TR;
  char *pname = abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr);
  string r = pname;
  try { 
    if (std::is_const<TR>::value) r += " const";
    if (std::is_volatile<TR>::value) r += " volatile";
    if (std::is_lvalue_reference<T>::value) r += "&";
    else if (std::is_rvalue_reference<T>::value) r += "&&";
  }
  catch(...) {
    abort();
  }
  free(pname);
  return r;
}

template <typename T>
void
foo (const T& t) {
  cout << type_name<decltype(t)>() << endl;
}

template <typename T> struct TD;

int
main (void)
{
  const Empty *c;
  foo (c);  
}

