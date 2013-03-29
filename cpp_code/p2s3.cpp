#include <iostream>
#include <cmath>

class ball_t
{
private:
  /* internal state */
  double m_x, m_y, m_vx, m_vy, m_t;
  static const double g;
public:
  /* Construction & destruction */
  explicit ball_t(double a_x = 0.0, double a_y = 0.0):
	  m_x(a_x), m_y(a_y), m_vx(0.0), m_vy(0.0), m_t(0.0) {}
  ~ball_t(void) {}
 
  /* Selectors */
  double get_x(void) const { return m_x; }
  double get_y(void) const { return m_y; }

  /* Behavior */
  void push(double v, double alpha);
  void fly(double time);
};

/* Static constant definition */
const double ball_t::g = 9.81;

void
ball_t::push(double v, double alpha)
{
  m_vx += v * cosf(alpha);
  m_vy += v * sinf(alpha);
}

void
ball_t::fly(double time)
{
  m_x += m_vx * time;
  m_y += m_vy * time - g * time * time;
  m_vy -= g * time;
}

int 
main(void)
{
  ball_t ball(0.0, 600.0);
  ball.push(30.0, 0.75);
  for(int i = 0; i != 10; ++i)
    {
      ball.fly(1.0);
      std::cout << "x = " << ball.get_x() 
	        << ", y = " << ball.get_y() << std::endl;
    }
  return 0;
}

