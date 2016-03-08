// first user for drawer

#include "sdlutil.hpp"

#include <sstream>
#include <string>

using namespace std;

const unsigned xsize = 640;
const unsigned ysize = 480;
const unsigned black = 0xff1010ff;
const unsigned white = 0xffffffff;

static bool 
f (unsigned x, unsigned y, int delta)
{
  unsigned res;
  res = ((x & y) * (x | y));
  return ((res >> delta) & 1);
}

static void
draw_internal (ISurface *s, int delta)
{
  unsigned ix, iy;
  unsigned width = s->w();
  unsigned height = s->h();

  s->fillwith (white);

  for (ix = 0; ix != width; ++ix)
    for (iy = 0; iy != height; ++iy)
      if (f (iy, ix, delta) != 0)
        s->putpixel (ix, iy, black);
}

int
main ()
{
  int delta = 0;

  auto draw_external = [&delta] (ISurface *s) { draw_internal (s, delta); };

  ViewPort *v = ViewPort::QueryViewPort (xsize, ysize, draw_external);

  for (delta = 4; delta < 10; ++delta)
    {
      std::ostringstream oss;
      oss << "funcmap" << delta << ".bmp";
      string s = oss.str();
      v->dump(s.c_str());
    }

  while (v->poll () == pollres::PROCEED)
    {
    }

  delete v;
  return 0;
}

