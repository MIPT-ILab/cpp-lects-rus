int printf(const char *, ...);

#define SQR(X) ((X)*(X))

int sqr(int x) {
  return x * x;
}

int main() {
  int x = 5;
  printf("%d\n", SQR(SQR(SQR(X))));
  printf("%d\n", sqr(sqr(sqr(x))));
}

