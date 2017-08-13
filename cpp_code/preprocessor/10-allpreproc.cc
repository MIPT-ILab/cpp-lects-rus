// compile with clang++

#define VAR 42

extern "C" {
int printf (const char*, ...);
int strlen (const char*);
}

int
main ()
{
  // 1.
  const char *привет = "Hello";

  // 2.
  int xst\
rlen = strlen(привет);

  // 3.
  /* replace me with space */

  // 5.
  int t = VAR;

  // 6.
  printf("\t%d\t%d\n", t, xstrlen);

  // 7.
  printf("\t%s\n", "Hello" "world");
}

