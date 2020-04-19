// Julia sets
// default is -0.7 0.0
// try also -0.7 0.1, -0.7 0.2 and -0.7 0.5
//           -0.9 0.2 is equally well

#define DYNAMIC

#include <cmath>
#include <complex>
#include <cstdlib>
#include <sstream>
#include <string>

#include "drawutil.hpp"

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

using cdt = std::complex<double>;
using namespace std::complex_literals;

const unsigned xsize = 1024;
const unsigned ysize = 768;
const unsigned black = 0xff1010ff;
const unsigned white = 0xffffffff;
#ifdef DYNAMIC
const unsigned maxiter = 30;
const double ARGSTEP = 0.01;
#else
const unsigned maxiter = 100;
#endif

static void draw_julia(DrawUtil::ISurface *s, cdt c) {
  // const int rmax = 0xff;
  // const int bmax = 0xff;
  double sz = 1.0 + std::sqrt(1.0 + 4.0 * std::abs(c));
  double stepx = sz / (double)xsize;
  double stepy = sz / (double)ysize;
  double x, y;

  s->fillwith(white);

  for (x = -sz; x < sz; x += stepx)
    for (y = -sz; y < sz; y += stepy) {
      cdt z = x + 1.0i * y;
      // bool res = true;
      unsigned cl = 0x0000aa;

      for (unsigned i = 0; i < maxiter; ++i) {
        if (std::abs(z) > sz) {
          cl = cl | (((i * 8) % 0xff) << 16) | (((i * 8) % 0xff) << 8);
          break;
        }

        z = z * z + c;
      }

      s->putlogpixel(x / sz, y / sz, cl);
    }
}

int
#if defined(_WIN32) || defined(WIN32)
WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
#else
main (int argc, char **argv)
#endif
{
  cdt c = -0.7;

#if defined(_WIN32) || defined(WIN32)
  int argc;
  LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
#else
#endif

  if (argc == 3) {
#if defined(_WIN32) || defined(WIN32)
    double re = _wtof(argv[1]);
    double im = _wtof(argv[2]);
#else
    double re = std::atof(argv[1]);
    double im = std::atof(argv[2]);
#endif
    c = re + 1.0i * im;
  }

  auto draw_external = [&c](DrawUtil::ISurface *s) { draw_julia(s, c); };

  auto *v = DrawUtil::QueryViewPort(xsize, ysize, draw_external);
  if (!v)
    abort();

  std::ostringstream oss;
  oss << "julia"
      << ".bmp";
  std::string s = oss.str();
  v->dump(s.c_str());

#ifdef DYNAMIC
  double abs = std::abs(c);
  double arg = std::arg(c);
#endif

  while (v->poll() == DrawUtil::pollres::PROCEED) {
#ifdef DYNAMIC
    arg += ARGSTEP;
    c = std::polar(abs, arg);
#endif
  }

  delete v;
  return 0;
}
