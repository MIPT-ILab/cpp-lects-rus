#pragma once

#include <cassert>
#include <functional>

namespace DrawUtil {

enum class pollres { PROCEED, STOP };

// unsigned shall be 32-bit type
static_assert(sizeof(unsigned) == 4);

// build color from parts
enum Offset { A = 24, R = 16, G = 8, B = 0 };

static inline constexpr unsigned
buildcolor(unsigned char a, unsigned char r,
           unsigned char g, unsigned char b) noexcept {
  return (unsigned{a} << Offset::A) | (unsigned{r} << Offset::R) |
         (unsigned{g} << Offset::G) | (unsigned{b} << Offset::B);
}

template <Offset off>
constexpr unsigned char cpart(unsigned color) noexcept {
  return (color >> off);
}

struct ISurface {
  virtual void putpixel(int x, int y, unsigned color) = 0;
  virtual void putlogpixel(double x, double y, unsigned color) = 0;
  virtual void fillwith(unsigned color) = 0;
  virtual unsigned w() const noexcept = 0;
  virtual unsigned h() const noexcept = 0;
  virtual ~ISurface() {}
};

// argument of key binding in special cases
enum KeySpecial { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

struct KeyPressed {
  bool is_special;
  union {
    KeySpecial k;
    char s;
  } u;
  KeyPressed(KeySpecial k) : is_special{true}, u{.k = k} {}
  KeyPressed(char s) : is_special{false}, u{.s = s} {}
  char special() const noexcept { assert(is_special); return u.k; }
  char regular() const noexcept { assert(!is_special); return u.s; }
};

struct IViewPort {
  virtual pollres poll() = 0;
  virtual void dump(const char *name) = 0;
  virtual void bindkeys(std::function<void(KeyPressed)> k) = 0;
  virtual ~IViewPort() {}
};

IViewPort *QueryViewPort(int w, int h, std::function<void(ISurface *)> c, bool resize = false);

} // namespace DrawUtil