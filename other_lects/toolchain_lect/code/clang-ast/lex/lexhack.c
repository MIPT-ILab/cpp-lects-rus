typedef int int_t;
int int_v = 5;
char p[] = {1, 2, 3, 4, 5, 6, 7};
int q = 5;

int main() {
  int a = (int_t) *p;
  int b = (int_v) *q;
  return a + b;
}

