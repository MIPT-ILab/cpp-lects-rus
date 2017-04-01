#include <cstdio>

using namespace std;
 
class foo {
public:
  foo () { printf ("foo::foo()\n"); }
  foo (const foo&) { printf ("foo::foo( const foo& )\n"); }
  ~foo () { printf ("foo::~foo()\n"); }
};

foo 
bar()
{ 
  foo local_foo; 
  return local_foo; 
}
 
int 
main()
{
  foo f = bar();
  return 0;
}

