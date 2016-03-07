// second user for drawer

#include "sdlutil.hpp"

#include <sstream>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

const unsigned xsize = 640;
const unsigned ysize = 480;
const double PI = 3.14159265;

static void
putlogpixel (SDL_Surface *s, double x, double y, Uint32 color)
{
  unsigned width = s->w;
  unsigned height = s->h;
 
  int logx = rint ((double) width * (x + 1.0) / 2.0);
  int logy = rint ((double) height * (y + 1.0) / 2.0);

  if (logx > (int) width) logx = width - 1;
  if (logx < 0) logx = 0;
  if (logy > (int) height) logy = height - 1;
  if (logy < 0) logy = 0;

  putpixel (s, logx, logy, color);
}

static void
draw_waves (SDL_Surface *s, double phase)
{
  const int rmax = 0xff;
  const int bmax = 0xff;
  const int SCALE = 3000;  
  const double FREQ = 1000.0 * PI / 180.0;
  int ix;
  double alpha = PI * 90.0 / 180.0;
  double alpha_min = - PI * 90.0 / 180.0;
  double a = sin (FREQ * phase);
  int rmask = 0x00, bmask = 0x00;

  fillwith (s, 0xffffffff);

  if (a > 0.0) 
    {
      bmask = rint (a * bmax);
    }
  else
    {
      rmask = rint ((-a) * rmax);
    }

  while(alpha > alpha_min)
    {
      double x = -1.0 + phase * cos (alpha);
      double y = phase * sin (alpha);
      putlogpixel (s, x, y, 0xff000000 | (rmask << 16) | bmask);
      alpha -= 0.1 * PI / 180.0;
    }
}

int
main ()
{
  clock_t start_phase = clock ();
  double dphase = 0.0;

  auto draw_external = [&dphase] (SDL_Surface *s) { draw_waves (s, dphase); };

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

