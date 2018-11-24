// first user for drawer

#include "sdlutil.hpp"

#include <sstream>
#include <string>

using namespace std;

const unsigned xsize = 1024;
const unsigned ysize = 768;
const unsigned black = 0xff1010ff;
const unsigned white = 0xffffffff;

static unsigned
and_or_carpet (unsigned x, unsigned y)
{
  unsigned res;
  res = ((x & y) * (x | y));
  return res;
}

using ftype_t = unsigned (unsigned, unsigned);

static void
draw_internal (ISurface *s, ftype_t f,  unsigned delta)
{
  unsigned ix, iy;
  unsigned width = s->w();
  unsigned height = s->h();

  s->fillwith (white);

  for (ix = 0; ix != width; ++ix)
    for (iy = 0; iy != height; ++iy)
      {
        unsigned res = f (iy, ix);
        bool pixel = ((res >> delta) & 1);
        if (pixel != 0)
          s->putpixel (ix, iy, black);
      }
}

int
#if defined(_WIN32) || defined(WIN32) 
WinMain ()
#else
main ()
#endif
{
  unsigned delta = 0;

  auto draw_external = [=, &delta] (ISurface *s) { 
     draw_internal (s, and_or_carpet, delta); 
  };

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

