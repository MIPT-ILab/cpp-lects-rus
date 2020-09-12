int foo(int *x) {
  return *x;
}

int main() {
  int t = 2;
  foo(&t);
  foo(nullptr);
}

