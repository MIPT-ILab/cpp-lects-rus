#include <iostream>
#include <utility>
#include <functional>
#include <stdexcept>

template<typename T, typename... Args> int 
pp_printf(const char* s, T&& value, Args&&... args) 
{ 
  while (*s) 
    { 
      if (*s == '%' && *++s != '%') 
        {
          /* ignore the character that follows the '%'! */
          std::cout << value;
          return printf(++s, args...) + 1;
        }
      std::cout << *s++;
    }
  throw std::runtime_error("extra arguments provided to printf");
}

int 
pp_printf(const char* s) {
  while (*s) {
    if (*s == '%' && *++s != '%') 
      throw std::runtime_error("invalid format string: missing arguments");
    std::cout << *s++;
  }
  return 0;
}

int
main (void)
{
  pp_printf ("%d... %d... %d..."
             "%d... %d... %s\n", 
             4, 3, 2, 1, 0, "Hello, world!");
  return 0;
}

