module second_module;

namespace hello {

int e = 42;

int foo(int x) {
  return x;
}

int bar() {
  return foo(e);
}

}