#include <cstdio>
const char * const helloworld = "Hello, world";
int main(void)
{
  std::printf("%s\n", ::helloworld);
  return 0;
}

