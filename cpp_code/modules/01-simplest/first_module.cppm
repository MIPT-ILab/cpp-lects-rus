export module first_module;

namespace hello {

int foo(int x) {
  return x;
}

export int e = 42;

export int bar() {
  return foo(e);
}

}