#include "sdlutil.hpp"

namespace DrawUtil {

ViewPort *v = nullptr;

IViewPort *QueryViewPort(int w, int h, std::function<void(ISurface *)> c) {
  if (v == nullptr)
    v = new ViewPort(w, h, c);
  return v;
}

constexpr int A = 24;
constexpr int R = 16;
constexpr int G = 8;
constexpr int B = 0;

template <int off> static Uint8 cpart(unsigned color) {
  return (color >> off) & 0xff;
}

void SDLSurface::putpixel(int x, int y, unsigned c) {
  SDL_SetRenderDrawColor(s_, cpart<R>(c), cpart<G>(c), cpart<B>(c),
                         cpart<A>(c));
  SDL_RenderDrawPoint(s_, x, y);
}

void SDLSurface::fillwith(unsigned c) {
  SDL_SetRenderDrawColor(s_, cpart<R>(c), cpart<G>(c), cpart<B>(c),
                         cpart<A>(c));
  SDL_RenderClear(s_); 
}

void SDLSurface::putlogpixel(double x, double y, unsigned color) {
  int width, height;
  SDL_GetRendererOutputSize(s_, &width, &height);

  int logx = rint((x + 1.0) * width / 2.0);
  int logy = rint((y + 1.0) * height / 2.0);

  if (logx >= width)
    logx = width - 1;
  if (logx < 0)
    logx = 0;
  if (logy >= height)
    logy = height - 1;
  if (logy < 0)
    logy = 0;

  putpixel(logx, logy, color);
}

// ViewPort methods

pollres ViewPort::poll() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      return pollres::STOP;
  }

  SDL_SetRenderTarget(ren, texture);
  SDLSurface s(ren);
  callback(&s);
  SDL_SetRenderTarget(ren, NULL);
  SDL_RenderCopy(ren, texture, NULL, NULL);
  SDL_RenderPresent(ren);
  return pollres::PROCEED;
}

void ViewPort::dump(const char *name) {
  SDL_SetRenderTarget(ren, texture);
  SDLSurface s(ren);
  callback(&s);
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
  SDL_RenderReadPixels(ren, NULL, surface->format->format, surface->pixels, surface->pitch);
  SDL_SaveBMP(surface, name);
  SDL_FreeSurface(surface);
  SDL_SetRenderTarget(ren, NULL);
}

}