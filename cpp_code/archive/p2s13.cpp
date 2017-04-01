#include <cstdio>

using namespace std;

class NamedObject {
public:
  virtual const char *whoareyou(void) const = 0;
};

class Pokemon : public NamedObject {
public:
  const char *whoareyou(void) const { return "Pokemon"; }
};

class DartVeider : public NamedObject {
public:
  const char *whoareyou(void) const { return "Dart Veider"; }
};

int check_DartVeider(NamedObject *p)
{
  if (dynamic_cast<DartVeider *>(p))
    {
      printf("You are Dart Veider!\n");
    }
  else
    {
      printf("You are not Dart Veider, you are %s\n", p->whoareyou());
    }
  return 0;
}

int main(void)
{
  DartVeider dv;
  Pokemon pm;
  check_DartVeider(&dv);
  check_DartVeider(&pm);
  return 0;
}
