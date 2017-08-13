extern C {
  int printf (const char*, ...);
}

#define hash_hash # ## #
#define mkstr(a) #a
#define proxy(a) mkstr(a)
#define EVAL(...) proxy(__VA_ARGS__)
#define concat(a) EVAL(a)
#define in_between(a) concat(a)
#define join(c, d) in_between(c hash_hash d)

int
main ()
{
  char p[] = join(x, y);
  printf("%s\n", p);
} 

