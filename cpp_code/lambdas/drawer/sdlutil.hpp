#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include <cstdlib>

#include <functional>

#include "drawutil.hpp"

namespace DrawUtil {

class SDLSurface : public ISurface {
  SDL_Renderer *s_;

public:
  SDLSurface(SDL_Renderer *s) : s_{s} {}
  unsigned w() const noexcept override {
    int w;
    SDL_GetRendererOutputSize(s_, &w, NULL);
    return w;
  }
  unsigned h() const noexcept override {
    int h;
    SDL_GetRendererOutputSize(s_, NULL, &h);
    return h;
  }
  void putpixel(int x, int y, unsigned c) override {
    SDL_SetRenderDrawColor(s_, cpart<R>(c), cpart<G>(c), cpart<B>(c), cpart<A>(c));
    SDL_RenderDrawPoint(s_, x, y);    
  }
  void fillwith(unsigned c) override {
    SDL_SetRenderDrawColor(s_, cpart<R>(c), cpart<G>(c), cpart<B>(c), cpart<A>(c));
    SDL_RenderClear(s_);    
  }
  void putlogpixel(double x, double y, unsigned c) override;
};

class ViewPort : public IViewPort {
  int width, height;
  SDL_Window *screen;
  SDL_Renderer *ren;
  SDL_Texture *texture;
  std::function<void(ISurface *)> callback;
  std::function<void(KeyPressed)> keybind;

public:
  ViewPort(int w, int h, std::function<void(ISurface *)> c, bool r)
    : width{w}, height{h}, callback{c}, keybind{nullptr} {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
      throw std::runtime_error(SDL_GetError());

    atexit(SDL_Quit);
    screen = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, width, height,
                              SDL_WINDOW_SHOWN | (r ? SDL_WINDOW_RESIZABLE : 0));
    if (screen == nullptr)
      throw std::runtime_error(SDL_GetError());

    ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
    if (ren == nullptr)
      throw std::runtime_error(SDL_GetError());

    texture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
                                SDL_TEXTUREACCESS_TARGET, width, height);
  }

  pollres poll() override;
  void dump(const char *name) override;
  void bindkeys(std::function<void(KeyPressed)> k) override {
    keybind = k;
  }

  ~ViewPort() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(screen);
  }
};

} // namespace DrawUtil
