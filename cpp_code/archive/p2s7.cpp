class A {
  public:
    A (const char *s) {}
    const char *f(void) { return "hello, world"; }
};

class B : public A {
  public:
    B() : A ( s = f() ) {}
  private:
    const char *s;
};

class Fruit {
  public:
    typedef int (* get_mass_t)(void);
    explicit Fruit(get_mass_t a_entry) { m_entry = a_entry; }
    int get_mass(void)
      { 
        return m_entry();
      }
  private:
    get_mass_t m_entry;
};

#include <cstdio>

using namespace std;

class NamedObject {
public:
  virtual void whoareyou(void) const = 0;
};

class Pickachu : public NamedObject {
public:
  void whoareyou(void) const { printf("Pickachu"); }
};

class DartVeider : public NamedObject {
public:
  void whoareyou(void) const { printf("Dart Veider"); }
};

void 
friendship(const NamedObject& n1, const NamedObject& n2)
{
  printf("Hello, I am "); n1.whoareyou(); printf("\n");
  printf("Hello, I am "); n2.whoareyou(); printf("\n");
  printf("Lets be friends!\n");
}

int 
main(void)
{
  Pickachu p;
  DartVeider d;
  friendship(p, d);
}

