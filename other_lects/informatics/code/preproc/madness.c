int printf(const char *, ...);

// #define 1 X

int Y = 1;

#define Y X
#define X Y

int main() {
  int X = 5;
  printf("%d\n", X + Y);
}

