#include <cstdio>

using namespace std;

template <typename Owner>
class LaserSword {
public:
  void hit(void)
    {
       static_cast<Owner*>(this)->use_power();
    }
};

class DartVeider: public LaserSword<DartVeider> {
public:
  void use_power(void) 
  {
    printf("Dart Veider uses power\n");
  }
};

int main(void)
{
  DartVeider d;
  d.hit();
  return 0;
}

