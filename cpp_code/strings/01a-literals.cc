#include <iostream>

using std::cout;
using std::endl;

int
main ()
{
  auto cstr = "Hello, world!";
  decltype(auto) cstra = "Hello, world!";
  char cmut[] = "Hello, world!";
  cout << sizeof("Hello, world!") << " "
       << sizeof(cstr) << " "
       << sizeof(cstra) << " " << endl
       << cstr << endl
       << cmut << endl
       << cstra << endl;
}

