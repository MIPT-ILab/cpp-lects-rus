#include <algorithm>

#include "sdlutil.hpp"

namespace DrawUtil {

ViewPort *v = nullptr;

IViewPort *QueryViewPort(int w, int h, std::function<void(ISurface *)> c, bool r) {
  if (v == nullptr)
    v = new ViewPort(w, h, c, r);
  return v;
}

void SDLSurface::putlogpixel(double x, double y, unsigned color) {
  int width, height;
  SDL_GetRendererOutputSize(s_, &width, &height);
  double w = width, h = height;

  int logx = std::clamp(rint((x + 1.0) * width / 2.0), 0.0, w);
  int logy = std::clamp(rint((y + 1.0) * height / 2.0), 0.0, h);
  putpixel(logx, logy, color);
}

// ViewPort methods

pollres ViewPort::poll() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      return pollres::STOP;
    if (keybind && (event.type == SDL_KEYDOWN)) {      
      SDL_Keycode kc = event.key.keysym.sym;
      switch(kc) {
        case SDLK_UP:
          keybind(KeyPressed{KEY_UP});
          break;
        case SDLK_DOWN:
          keybind(KeyPressed{KEY_DOWN});
          break;
        case SDLK_LEFT:
          keybind(KeyPressed{KEY_LEFT});
          break;
        case SDLK_RIGHT:
          keybind(KeyPressed{KEY_RIGHT});
          break;
        case SDLK_p:
          keybind(KeyPressed{'p'});
          break;
        case SDLK_d:
          keybind(KeyPressed{'d'});
          break;
        case SDLK_r:
          keybind(KeyPressed{'r'});
          break;
        case SDLK_s:
          keybind(KeyPressed{'s'});
          break;
        case SDLK_PLUS:
        case SDLK_KP_PLUS:
          keybind(KeyPressed{'+'});
          break;
        case SDLK_MINUS:
        case SDLK_KP_MINUS:
          keybind(KeyPressed{'-'});
          break;
      }
    }
  }

  SDLSurface s{ren};
  callback(&s);
  SDL_RenderPresent(ren);
  return pollres::PROCEED;
}

void ViewPort::dump(const char *name) {
  SDL_SetRenderTarget(ren, texture);
  SDLSurface s(ren);
  callback(&s);
  SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  SDL_Surface *surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
  SDL_RenderReadPixels(ren, NULL, surface->format->format, surface->pixels,
                       surface->pitch);
  SDL_SaveBMP(surface, name);
  SDL_FreeSurface(surface);
  SDL_SetRenderTarget(ren, NULL);
}

} // namespace DrawUtil