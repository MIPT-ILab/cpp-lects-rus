#include <cstdio>

using namespace std;

class Pokemon {
public:
  void whoareyou(void) const { printf("Pokemon"); }
};

class DartVeider {
public:
  void whoareyou(void) const { printf("Dart Veider"); }
};

template <typename T, typename U>
void friendship(const T& n1, const U& n2)
{
  printf("Hello, I am "); n1.whoareyou(); printf("\n");
  printf("Hello, I am "); n2.whoareyou(); printf("\n");
  printf("Lets be friends!\n");
}

int main(void)
{
  Pokemon p;
  DartVeider d;
  friendship(p, d);
  return 0;
}

