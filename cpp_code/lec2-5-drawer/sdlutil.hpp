#ifndef SDLUTIL_GUARD_
#define SDLUTIL_GUARD_

#include <cstdlib>
#include <cmath>
#include <SDL/SDL.h>

#include <functional>

using namespace std;

enum class pollres 
{
  PROCEED,
  STOP
};

void putpixel(SDL_Surface *surface, int x, int y, Uint32 color);
void fillwith (SDL_Surface *screen, Uint32 color);

class ViewPort
{
  int width, height;
  SDL_Surface *screen;
  std::function<void(SDL_Surface*)> callback;
  static ViewPort *v;

  ViewPort (int w, int h, std::function<void(SDL_Surface*)> c) 
    : width (w), height (h), callback(c)
  {   
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
      throw runtime_error (SDL_GetError());

    atexit(SDL_Quit);    
    screen = SDL_SetVideoMode(width + 1, height + 1, 0, SDL_DOUBLEBUF);
    if (screen == NULL)
      throw runtime_error (SDL_GetError());
  }

public:
  pollres poll ();
  void dump (const char *name);

  static ViewPort *
  QueryViewPort (int w, int h, std::function<void(SDL_Surface*)> c)
  {
    if (!v)
      v = new ViewPort(w, h, c);
    return v;
  }

  ~ViewPort()
  {
    SDL_FreeSurface(screen);    
  }
};

#endif
