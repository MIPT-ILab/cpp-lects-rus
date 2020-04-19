// funcbitmap: bit function visualizer

#include <sstream>
#include <string>

#include "drawutil.hpp"

constexpr unsigned xsize = 1024;
constexpr unsigned ysize = 768;
constexpr unsigned black = DrawUtil::buildcolor(0xff, 0x10, 0x10, 0xff);
constexpr unsigned white = DrawUtil::buildcolor(0xff, 0xff, 0xff, 0xff);

static unsigned and_or_carpet(unsigned x, unsigned y) {
  unsigned res;
  res = ((x & y) * (x | y));
  return res;
}

using ftype_t = unsigned(unsigned, unsigned);

static void draw_internal(DrawUtil::ISurface *s, ftype_t f, unsigned delta) {
  unsigned ix, iy;
  unsigned width = s->w();
  unsigned height = s->h();

  s->fillwith(white);

  for (ix = 0; ix != width; ++ix)
    for (iy = 0; iy != height; ++iy) {
      unsigned res = f(iy, ix);
      bool pixel = ((res >> delta) & 1);
      if (pixel != 0)
        s->putpixel(ix, iy, black);
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

  auto draw_external = [=, &delta](DrawUtil::ISurface *s) {
    draw_internal(s, and_or_carpet, delta);
  };

  auto *v = DrawUtil::QueryViewPort(xsize, ysize, draw_external);

  for (delta = 4; delta < 10; ++delta) {
    std::ostringstream oss;
    oss << "funcmap" << delta << ".bmp";
    std::string s = oss.str();
    v->dump(s.c_str());
  }

  while (v->poll() == DrawUtil::pollres::PROCEED) {
  }

  delete v;
  return 0;
}
