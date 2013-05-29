struct pair_t 
{ 
  int x; 
  int y;
  pair_t transpose_pair(void); 
};

pair_t 
pair_t::transpose_pair(void)
{
  pair_t pr = {this->y, this->x};
  return pr;
} 

class ball_t
{
public:
  /* Construction & destruction */
  ball_t(double a_x = 0.0, double a_y = 0.0):
    m_x(a_x), m_y(a_y), m_vx(0.0), m_vy(0.0), m_t(0.0) {}
  ~ball_t(void) {}
private:
  double m_x, m_y, m_vx, m_vy, m_t;
};

int emulateBall(ball_t b) { /* ... */ }

int foo(void)
{
  emulateBall(1.0); /* ??? but legal */
}

class Plum {
public:
  Plum():m_mass(3){}
  int get_mass (void) const {return m_mass;}
private:
  int m_mass;
};

class Apple {
public:
  Apple():m_mass(5){}
  int get_mass (void) const {return m_mass;}
private:
  int m_mass;
};

class Pear {
public:
  Pear():m_mass(6){}
  int get_mass (void) const {return m_mass;}
private:
  int m_mass;
};


