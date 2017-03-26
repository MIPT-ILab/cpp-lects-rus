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

  // s->fillwith (0xffffffff);

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
#if defined(_WIN32) || defined(WIN32)
WinMain ()
#else
main ()
#endif
{
  const unsigned xsize = 800;
  const unsigned ysize = 800;

  clock_t start_phase = clock ();
  double dphase = 0.0;
  double xcenter = -0.5;
  double ycenter = 0.3;

  auto draw_external = [xcenter, ycenter, &dphase] (ISurface *s) { draw_waves (s, xcenter, ycenter, dphase); };

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

