#include "sdlutil.hpp"

double phase = 0.0;
const double dphase = 0.01;
const double PI = 3.1415926;

void
test_draw (SDL_Surface *screen)
{
  const int SCALE = 3000;
  const double FREQ = 1000.0 * PI / 180.0;
  int ix;
  int width = screen->w;
  int height = screen->h;

  paint_color (screen, 0xffffffff);

  for (ix = 0; ix != 2*SCALE; ++ix)
    {
      double x, y;
      x = ((double) (ix - SCALE)) / SCALE;
      y = sin (FREQ * x + phase);
      int logx = rint ((double) width * (x + 1.0) / 2.0);
      int logy = rint ((double) height * (y + 1.0) / 2.0);

      if (logx > width) logx = width;
      if (logx < 0) logx = 0;
      if (logy > height) logy = height;
      if (logy < 0) logy = 0;

      putpixel (screen, logx, logy, 0xff1010ff);
    }
}


int
main ()
{
  ViewPort *v = ViewPort::create_ViewPort (640, 480, test_draw);
  while (v->poll () == 1)
    {
      phase += dphase;
    }
  delete v;
  return 0;
}

