module second_module;

int e = 42;

int foo(int x) {
  return x;
}

int bar() {
  return foo(e);
}

