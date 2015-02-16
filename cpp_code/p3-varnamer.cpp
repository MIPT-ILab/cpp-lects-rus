#include <cstdio>
#include <string>
 
using namespace std;
 
template <int *foo>
class VariableNamer {
public:
  static const char *name;
};

int baz = 7;
int bar = 42;
 
template<>
const char * VariableNamer< &baz >::name = "baz";

template<>
const char * VariableNamer< &bar >::name = "bar";
  
template <int *foo> void 
detect_global (void)
{
  printf ("called with: %s = %d\n", VariableNamer<foo>::name, *foo);
}

int 
main( int argc, char ** argv ) 
{
  baz = baz / 2;
  bar = bar + baz;
  detect_global <&bar> ();
  detect_global <&baz> ();
  return 0;
}

