#include <cstdlib>
#include <cstdio>
#include <cassert>

using namespace std;

class Fruit {
public:
  Fruit(int a_mass):m_mass(a_mass){}
  int get_mass (void) const { return m_mass; }
protected:
  int m_mass;
};

class Apple: public Fruit {
/* Apple-specific code */
public:
  Apple():Fruit(5){}
};

class Pear: public Fruit {
/* Pear-specific code */
public:
  Pear():Fruit(6){}
};

class Plum: public Fruit {
/* Plum-specific code */
public:
  Plum():Fruit(3){}
};

int main(void)
{
  Apple a; Pear b; Plum c;
  assert (a.get_mass() < b.get_mass());
  assert (a.get_mass() > c.get_mass());
  return 0;
}

