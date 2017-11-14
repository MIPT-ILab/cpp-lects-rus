#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

template <typename T> class AddSpace {
  const T& ref;
public:
  AddSpace(const T& r): ref(r) {}
  void dump_space(ostream& os) { os << ref << ' '; }
};

template <typename T>
ostream& operator<< (ostream& os, AddSpace<T> s) {
  s.dump_space(os);
  return os;
}

template <typename ... T>
auto fh (string name, T ... args) {
  cout << name << "(" << sizeof...(args) << "): ";

  // вывод конструктором, так-то должно быть AddSpace<T>(args)
  (cout << ... << AddSpace(args)) << endl;
  auto result = (args + ...);
  return result;
}

template <typename ... T>
auto f (T ... args) {
  return fh("f", args...);
}

template <typename ... T>
auto h (T ... args) {
  return fh("h", args...);
}

template <typename ... T>
void foo (T ... args) {
  f(h(args...) + h(args)...);
}

template <typename ... T>
void bar (T ... args) {
  f(h(args, args...)...);
}

int
main (void)
{
  cout << "foo:" << endl; 
  foo(1, 2, 3);
  cout << "bar:" << endl; 
  bar(1, 2, 3);
}

