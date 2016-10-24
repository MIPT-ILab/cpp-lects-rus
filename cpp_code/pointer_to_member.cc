#include <stdio.h>

struct foo {
  int bar() { printf ("bar\n"); }
};

template <typename T>
void Apply (T* t, int (T::*bar)() ) {
  (t ->* bar) ();
}

int main (void) {
  int (foo::*pbar)() = &foo::bar;
  foo f;

  Apply (&f, pbar);

  return 0;
}


