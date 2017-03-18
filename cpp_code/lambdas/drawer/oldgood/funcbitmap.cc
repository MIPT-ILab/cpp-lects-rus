// first user for drawer

#include "sdlutil.hpp"

#include <sstream>
#include <string>

using namespace std;

const unsigned xsize = 640;
const unsigned ysize = 480;
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
draw_internal (ISurface *s, ftype_t *f,  unsigned delta)
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

struct data_internal
{
  unsigned delta;
  ftype_t *f;
};

static void
draw_external (ISurface *s, void *data)
{
  struct data_internal *d = (struct data_internal *) data;
  draw_internal (s, d->f, d->delta);
}

int
main ()
{
  data_internal data = {0, &and_or_carpet};

  ViewPort *v = ViewPort::QueryViewPort (xsize, ysize, draw_external, (void *)&data);

  for (data.delta = 4; data.delta < 10; ++data.delta)
    {
      std::ostringstream oss;
      oss << "funcmap" << data.delta << ".bmp";
      string s = oss.str();
      v->dump(s.c_str());
    }

  while (v->poll () == pollres::PROCEED)
    {
    }

  delete v;
  return 0;
}

