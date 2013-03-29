#include <cstdio>

class DeathStar
{
public:
  DeathStar(const char *name) : m_name(name)
    {
       m_dv.starptr = this;
    }

  class DartVeider
  {
    public:
      void whoareyou() const
        {
          printf("I am Dart Veider, flying on %s\n", starptr ? starptr->m_name : "hmm... I don't know where");
        }
      DeathStar *starptr;    
  };

  void ask_dart_veider() const { m_dv.whoareyou(); }

private:
  DartVeider m_dv;
  const char *m_name;
};

int main(void)
{
  DeathStar d("Old Good Death Star");
  d.ask_dart_veider();
  return 0;
}

