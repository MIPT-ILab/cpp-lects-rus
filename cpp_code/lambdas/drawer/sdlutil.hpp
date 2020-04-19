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
  void putpixel(int x, int y, unsigned color) override;
  void putlogpixel(double x, double y, unsigned color) override;
  void fillwith(unsigned color) override;
};

class ViewPort : public IViewPort {
  int width, height;
  SDL_Window *screen;
  SDL_Renderer *ren;
  SDL_Texture *texture;
  std::function<void(ISurface *)> callback;  

public:
  ViewPort(int w, int h, std::function<void(ISurface *)> c)
      : width(w), height(h), callback(c) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
      throw std::runtime_error(SDL_GetError());

    atexit(SDL_Quit);
    screen = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, width, height,
                              SDL_WINDOW_SHOWN);
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

  ~ViewPort() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(screen);
  }
};

}


