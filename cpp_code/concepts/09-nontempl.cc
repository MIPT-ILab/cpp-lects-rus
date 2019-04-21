int foo(long l) requires (sizeof(long) == 4) {
  return l;
}

int foo(long l) requires (sizeof(long) == 16) {
  return l;
}

int main () {
  foo(1);
}