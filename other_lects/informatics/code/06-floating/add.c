int add(int x, int y) {
  return x + y;
}

unsigned addu(unsigned x, unsigned y) {
  return x + y;
}

void __attribute__((noinline)) 
foo(float *pf) {}

int
main() {
  float f = 0.1;
  foo(&f);
}

