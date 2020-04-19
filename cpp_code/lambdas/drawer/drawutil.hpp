#pragma once

#include <functional>

namespace DrawUtil {

enum class pollres { PROCEED, STOP };

// unsigned shall be 32-bit type
static_assert(sizeof(unsigned) == 4);

struct ISurface {
  virtual void putpixel(int x, int y, unsigned color) = 0;
  virtual void putlogpixel(double x, double y, unsigned color) = 0;
  virtual void fillwith(unsigned color) = 0;
  virtual unsigned w() const = 0;
  virtual unsigned h() const = 0;
  virtual ~ISurface() {}
};

struct IViewPort {
  virtual pollres poll() = 0;
  virtual void dump(const char *name) = 0;
  virtual ~IViewPort() {}
};

IViewPort *QueryViewPort(int w, int h, std::function<void(ISurface *)> c);

}