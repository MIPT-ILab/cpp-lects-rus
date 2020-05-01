int printf(const char *, ...);

int x = 2;
int y = 3;

void foo() {
  x = (x + y) * (x - y);
  y = x / 5;
  x = x - y * 7;
  y = x / 13;
  x = (y + 23) % 47;
}

void bar() {
  x += 4;
}

int main() {
  if (x > 3)
    foo();
  else
    bar();
  printf("%d\n", x);
}

