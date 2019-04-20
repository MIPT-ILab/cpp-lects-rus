long long sumall(unsigned char a, short b, int c, long d, long long e) {
  asm("");
  return a + b + c + d + e;
}

int
main () {
  int res = sumall(50, 1500, 18800, (1l << 23), (1ll << 46));
  return res;
}
