#include <cstdio>
namespace hellowapp {
const char * const helloworld = "Hello, world";
}
int main(void)
{
  std::printf("%s\n", hellowapp::helloworld);
  return 0;
}

