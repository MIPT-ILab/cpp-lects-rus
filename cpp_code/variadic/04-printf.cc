#include <iostream>
#include <utility>
#include <functional>
#include <stdexcept>

using std::cout;
using std::endl;
using std::forward;
using std::runtime_error;

int ts_printf(const char* s);

template<typename T, typename... Args> int 
ts_printf(const char* s, T&& value, Args&&... args) { 
  while (*s) {
    if (*s == '%' && *++s != '%') {
      /* ignore the character that follows the '%'! */
      cout << value;
      return ts_printf(++s, forward<Args>(args)...) + 1;
    }
    cout << *s++;
  }    
  throw std::runtime_error("extra arguments provided to printf");
}

int ts_printf(const char* s) {
  while (*s) {
    if (*s == '%' && *++s != '%') 
      throw runtime_error("invalid format string: missing arguments");
    cout << *s++;
  }
  return 0;
}

int
main (void)
{
  ts_printf ("%d... %d... %d... "
             "%d... %d... %%... %s\n", 
             4, 3, 2, 1, "Hello, world!");
  return 0;
}

