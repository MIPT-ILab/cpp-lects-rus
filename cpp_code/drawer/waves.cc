// second user for drawer

#include "sdlutil.hpp"

#include <sstream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

static void
draw_waves (ISurface *s, double xcenter, double ycenter, double phase)
{
  const double PI = 3.14159265;
  const int rmax = 0xff;
  const int bmax = 0xff;
  const double FREQ = 1000.0 * PI / 180.0;
  double alpha = 0.0;
  const double alpha_max = 2.0 * PI;
  double a = sin (FREQ * phase);
  int rmask = 0x00, bmask = 0x00;

  s->fillwith (0xffffffff);

  if (a > 0.0) 
    {
      bmask = rint (a * bmax);
    }
  else
    {
      rmask = rint ((-a) * rmax);
    }

  while(alpha < alpha_max)
    {
      double x = xcenter + phase * cos (alpha);
      double y = ycenter + phase * sin (alpha);
      s->putlogpixel (x, y, 0xff000000 | (rmask << 16) | bmask);
      alpha += 0.1 * PI / 180.0;
    }
}

int
main ()
{
  const unsigned xsize = 500;
  const unsigned ysize = 500;

  clock_t start_phase = clock ();
  double dphase = 0.0;

  auto draw_external = [&dphase] (ISurface *s) { draw_waves (s, -0.5, 0.3, dphase); };

  ViewPort *v = ViewPort::QueryViewPort (xsize, ysize, draw_external);

  while (v->poll () == pollres::PROCEED)
    {
      const double SPEEDUP = 1.0; 
      clock_t phase = clock ();
      dphase = SPEEDUP * (((double)phase - (double)start_phase) / CLOCKS_PER_SEC);

      if (dphase > 1.5)
        start_phase = clock ();
    }

  delete v;
  return 0;
}

