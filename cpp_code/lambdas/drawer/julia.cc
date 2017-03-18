// Julia sets

#include "sdlutil.hpp"

#include <complex>
#include <cmath>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;
using cdt = std::complex<double>;

const unsigned xsize = 640;
const unsigned ysize = 480;
const unsigned black = 0xff1010ff;
const unsigned white = 0xffffffff;

static void
draw_julia (ISurface *s, cdt c)
{
  //const int rmax = 0xff;
  //const int bmax = 0xff;
  double sz = 1.0 + std::sqrt(1.0 + 4.0 * std::abs(c));
  double step = sz/640.0;
  double x, y;
  unsigned maxiter = 0xff;

  s->fillwith (white);

  for (x = -sz; x < sz; x += step)
    for (y = -sz; y < sz; y += step)
      {
        cdt z = x + 1.0i * y;
        // bool res = true;
        unsigned cl = 0xff0000ff; //| (rmask << 16) | (gmask << 8)

        for (unsigned i = 0; i < maxiter; ++i)
          {
            if (std::abs(z) > sz) {
              cl = 0xff000000 | (((i*8) % 0xff) << 16) | (((i*8) % 0xff) << 8);
              break;
            }
            z = z * z * z + c; 
          }

        s->putlogpixel (x/sz, y/sz, cl);
      }
}

int
#if defined(_WIN32) || defined(WIN32)
WinMain (int argc, char **argv)
#else
main (int argc, char **argv)
#endif
{
  cdt c = -1.0i;

  if (argc == 3) {
    double re = std::atof(argv[1]);
    double im = std::atof(argv[2]);
    c = re + 1.0i * im;
  }


  auto draw_external = [&c] (ISurface *s) { draw_julia (s, c); };

  ViewPort *v = ViewPort::QueryViewPort (xsize, ysize, draw_external);

// for (delta = 4; delta < 10; ++delta)
//    {
   std::ostringstream oss;
   oss << "julia" << ".bmp";
   string s = oss.str();
   v->dump(s.c_str());
//    }

  while (v->poll () == pollres::PROCEED)
    {
    }

  delete v;
  return 0;
}

