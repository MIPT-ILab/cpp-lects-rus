#include <cstdio>
#include <cstdlib>

using namespace std;

class NamedObject {
public:
  virtual void whoareyou(void) const = 0;
};

class Pokemon : public NamedObject {
public:
  void whoareyou(void) const { printf("Pokemon"); }
};

class DartVeider : public NamedObject {
public:
  void whoareyou(void) const { printf("Dart Veider"); }
};

void friendship(const NamedObject& n1, const NamedObject& n2)
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

