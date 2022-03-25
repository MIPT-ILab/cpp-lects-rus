// Julia sets
// default is -7.0 0.0
// try also -0.7 0.1, -0.7 0.2 and -0.7 0.5
//          -0.9 0.2 is equally well
//          0.3 0.7 awesome
//
// Alternative Windows build
// cl /EHsc /O2 /std:c++20 sdlutil.cc julia.cc /Fe:julia /link SDL2.lib shell32.lib

#define DYNAMIC

#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

#include "drawutil.hpp"

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

using cdt = std::complex<double>;
using namespace std::complex_literals;

using std::abs;
using std::max;

constexpr int def_bigsize = 1000;
constexpr int def_xsize = 1024;
constexpr int def_ysize = 768;
constexpr unsigned black = 0xff1010ff;
constexpr unsigned white = 0xffffffff;
#ifdef DYNAMIC
constexpr unsigned maxiter = 100;
constexpr double ARGSTEP = 0.01;
#else
constexpr unsigned maxiter = 100;
#endif
const double sq2 = sqrt(2.0);

static void draw_julia(DrawUtil::ISurface *s, cdt c, cdt center, double sz) {  
  constexpr unsigned char clblue = 0xaa;
  constexpr unsigned cmod = 8;

  int xsize = s->w();
  int ysize = s->h();
  s->fillwith(white);
  for (int ix = -xsize / 2; ix < xsize / 2; ix += 1)
    for (int iy = -ysize / 2; iy < ysize / 2; iy += 1) {
      auto x = 2.0 * sz * ix / def_bigsize;
      auto y = 2.0 * sz * iy / def_bigsize;
      auto z = center + x + 1.0i * y;
      auto cl = DrawUtil::buildcolor(0, 0, 0, clblue);

      for (unsigned i = 0; i < maxiter; ++i) {
        if (abs(z) > max(2.0 * sz, 4.0)) {
          cl = DrawUtil::buildcolor(0, i * cmod, i * cmod, clblue);
          break;
        }
        z = z * z + c;
      }

      s->putpixel(ix + (xsize / 2), iy + (ysize / 2), cl);
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
  cdt center = 0.0;
  clock_t start_phase = clock();

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

  double abs = std::abs(c);
  double arg = std::arg(c);
  double argmul = 1.0;
  double sz = 2.0;
  bool pause = false;
  int dumpnum = 0;
  std::function<void(std::string)> vdumpf = nullptr;

  auto draw_external = [&c, &center, &sz](DrawUtil::ISurface *s) { draw_julia(s, c, center, sz); };
  
  // [&] instead of [&sz, &center, &pause, &dumpnum, &vdumpf, &argmul]
  auto key_control = [&](DrawUtil::KeyPressed k) mutable {
    if (k.is_special) {
      switch(k.special()) {
        case DrawUtil::KeySpecial::KEY_UP:
          center -= 0.1i * sz;
          break;
        case DrawUtil::KeySpecial::KEY_DOWN:
          center += 0.1i * sz;
          break;
        case DrawUtil::KeySpecial::KEY_LEFT:
          center -= 0.1 * sz;
          break;
        case DrawUtil::KeySpecial::KEY_RIGHT:
          center += 0.1 * sz;
          break;
      }
    }
    else {
      switch(k.regular()) {
        case '+':
          sz -= 0.1 * sz;
          break;
        case '-':
          sz += 0.1 * sz;
          break;
        case 'p':
          pause = !pause;
          break;
        case 's':
          arg += argmul * sz * ARGSTEP;
          break;
        case 'd': {
          if (vdumpf) {
            std::ostringstream os;
            os << "julia" << dumpnum << ".bmp";          
            vdumpf(os.str());
            dumpnum += 1;
          }
          break;
        }
        case 'r':
          argmul = -argmul;
          break;
      }
    }
  };

  auto *v = DrawUtil::QueryViewPort(def_xsize, def_ysize, 
                                   draw_external, true);
  vdumpf = [v](std::string s) { v->dump(s.c_str()); };
  v->bindkeys(key_control);

  while (v->poll() == DrawUtil::pollres::PROCEED) {
    const double SPEEDUP = 0.3;
    clock_t phase = clock();
    double dph = phase;
    double dphase = SPEEDUP * ((dph - start_phase) / CLOCKS_PER_SEC);
    start_phase = phase;
    
    if (!pause)
      arg += argmul * dphase;
    c = std::polar(abs, arg);
  }

  delete v;
  return 0;
}
