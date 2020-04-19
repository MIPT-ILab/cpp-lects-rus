#ifndef SDLUTIL_GUARD_
#define SDLUTIL_GUARD_

#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>

#include <functional>

using namespace std;

enum class pollres { PROCEED, STOP };

struct ISurface {
  virtual void putpixel(int x, int y, Uint32 color) = 0;
  virtual void putlogpixel(double x, double y, Uint32 color) = 0;
  virtual void fillwith(Uint32 color) = 0;
  virtual unsigned w() const = 0;
  virtual unsigned h() const = 0;
};

class SDLSurface : public ISurface {
  SDL_Renderer *s_;

public:
  SDLSurface(SDL_Renderer *s) : s_{s} {}
  unsigned w() const override {
    int w;
    SDL_GetRendererOutputSize(s_, &w, NULL);
    return w;
  }
  unsigned h() const override {
    int h;
    SDL_GetRendererOutputSize(s_, NULL, &h);
    return h;
  }
  void putpixel(int x, int y, Uint32 color) override;
  void putlogpixel(double x, double y, Uint32 color) override;
  void fillwith(Uint32 color) override;
};

class ViewPort {
  int width, height;
  SDL_Window *screen;
  SDL_Renderer *ren;
  SDL_Texture *texture;
  std::function<void(ISurface *)> callback;
  static ViewPort *v;

  ViewPort(int w, int h, std::function<void(ISurface *)> c)
      : width(w), height(h), callback(c) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
      throw runtime_error(SDL_GetError());

    atexit(SDL_Quit);
    screen = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, width, height,
                              SDL_WINDOW_SHOWN);
    if (screen == nullptr)
      throw runtime_error(SDL_GetError());

    ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
    if (ren == nullptr)
      throw runtime_error(SDL_GetError());

    texture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
                                SDL_TEXTUREACCESS_TARGET, width, height);
  }

public:
  pollres poll();
  void dump(const char *name);

  static ViewPort *QueryViewPort(int w, int h,
                                 std::function<void(ISurface *)> c) {
    if (v == nullptr)
      v = new ViewPort(w, h, c);
    return v;
  }

  ~ViewPort() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(screen);
  }
};

#endif
