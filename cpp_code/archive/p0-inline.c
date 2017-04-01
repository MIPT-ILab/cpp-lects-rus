#include <stdio.h>
#include <stdlib.h>

inline int
my_assert (int b, const char *str)
{
  if (!b)
    {
      fprintf (stderr, "Assertion failed: %s\n", str);
      exit (-1);
    }
  return 0;
}

int
main (int argc, char **argv)
{
  my_assert (argc > 0, "argc <= 0");
  return 0;
}

