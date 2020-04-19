int printf(const char *, ...);

#define h_h # ## #
#define mkstr(a) # a
#define betw(a) mkstr(a)
#define join(c, d) betw(c h_h d)

int main() {
  char p[] = join(x, y);
  printf("%s\n", p); // что на экране?
}
