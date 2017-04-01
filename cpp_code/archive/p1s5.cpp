/* foo.h */
namespace foo {
int bar(void);
}
/* foo.cpp */
int foo::bar(void) { /* ... */ }

namespace foo {
int y;
}
namespace {
int y;
void buz(int x) { y = x; } /* ok */
}
namespace buz {
void buz(int x) { foo::y = x; } /* ok */
}

namespace ns {
  struct S {};
  void f (S x) {}
}

void g(void)
{
  ns::S x;
  f(x); /* ok, f is ns::f */
}

