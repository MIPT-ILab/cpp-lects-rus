typedef struct pair 
{ 
  int x; 
  int y; 
} pair_t;

pair_t 
transpose_pair(pair_t pa)
{
  pair_t pr = {pa.y, pa.x};
  return pr;
} 

struct ball
{
  double t;
  double vx;
  double vy;
  double x;
  double y;
  void push(double v, double alpha);
  void fly(double time);
};

void ball::push(double v, double alpha){}

void ball::fly(double time){}

ball foo(void)
{
  ball a_ball;
  a_ball.vx = 5.0; /* sad, but ok */
  a_ball.push(5.0, 0.75); /* ok */
  a_ball.x = -1.0; /* hmm... still ok */  
  return a_ball;
}

#include <cassert>
#include <cmath>

using namespace std;

struct ball_t
{
private:
  double m_x;
  double m_y;
  double m_vx;
  double m_vy;
  double m_t;
public:
  void push(double a_v, double a_alpha);
  void fly(double a_time);
};

void ball_t::fly(double a_time) {}

void
ball_t::push(double a_v, double a_alpha)
{
  assert(a_v > 0);
  m_vx += a_v * cosf(a_alpha); /* ok */
  m_vy += a_v * sinf(a_alpha);
}

ball_t bar(void)
{
  ball_t ball;
#if 0
  ball.m_vx = 5.0; /* fail */
#endif
  ball.push(5.0, 0.75); /* ok */
  return ball;
}

