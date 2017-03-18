#include "sdlutil.hpp"

ViewPort* ViewPort::v = nullptr;

// standalone ones

static void
putpixel (SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    default:
       throw runtime_error("putpixel failure");
    }
}

static void
fillwith (SDL_Surface *screen, Uint32 color)
{
  int res = SDL_FillRect (screen, nullptr, color);
  if (res != 0)
    throw runtime_error (SDL_GetError());
}

// SDLSurface methods

void 
SDLSurface::putpixel (int x, int y, Uint32 color)
{
  ::putpixel (s, x, y, color);
}

void 
SDLSurface::fillwith (Uint32 color)
{
  ::fillwith (s, color);
}

void
SDLSurface::putlogpixel (double x, double y, Uint32 color)
{
  unsigned width = s->w;
  unsigned height = s->h;

  int logx = rint ((double) width * (x + 1.0) / 2.0);
  int logy = rint ((double) height * (y + 1.0) / 2.0);

  if (logx > (int) width) logx = width - 1;
  if (logx < 0) logx = 0;
  if (logy > (int) height) logy = height - 1;
  if (logy < 0) logy = 0;

  putpixel (logx, logy, color);
}


// ViewPort methods

pollres
ViewPort::poll ()
{
  SDLSurface s(screen);
  SDL_Event event;
  while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      return pollres::STOP;
    }
  SDL_LockSurface(screen);
  callback (&s, data);
  SDL_UnlockSurface(screen);
  SDL_Flip(screen);
  return pollres::PROCEED;
}

void 
ViewPort::dump (const char *name)
{
  SDL_Surface* layer = SDL_CreateRGBSurface(SDL_HWSURFACE, width + 1, height + 1,
    screen->format->BitsPerPixel,
    screen->format->Rmask,
    screen->format->Gmask,
    screen->format->Bmask,
    screen->format->Amask
  );

  if (layer == nullptr)
    throw runtime_error (SDL_GetError());

  SDLSurface s(layer);

  SDL_LockSurface(layer);
  callback (&s, data);
  SDL_UnlockSurface(layer);

  SDL_SaveBMP(layer, name);
}

