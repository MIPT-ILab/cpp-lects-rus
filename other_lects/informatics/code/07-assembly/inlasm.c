int foo(int x) {
  int y;
  asm("mov %0, %1\n":"=r"(y):"r"(x));
  return y;
}

