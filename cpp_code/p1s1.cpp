#include <cassert>

using namespace std;

char a[] = "abcdefgh";
char *b = "abcdefgh";

int main(void)
{
  assert (a[3] == b[3]);
  return 0;
}

