#include <stdlib.h>

double epsilon = 0.1;

int 
in_between (double x, double ymin, double ymax)
{
  return (x <= ymax) && (x >= ymin);
}

typedef double (get_t)(void *);

struct celestial_body_vmt
{
  get_t *pget_x;
  get_t *pget_y;
/* ... */
};

struct icelestial_body
{
  struct celestial_body_vmt vtable;
  /* ... */
};

void
icelestial_ctor(struct icelestial_body *ths, get_t *pget_x, get_t *pget_y)
{
  ths->vtable.pget_x = pget_x;
  ths->vtable.pget_y = pget_y;
  /* ... */
}

struct celestial_body
{
  struct icelestial_body intf;
  double x, y;
  /* ... */
};

double celestial_get_x(void *ths) { return ((struct celestial_body *)ths)->x; }
double celestial_get_y(void *ths) { return ((struct celestial_body *)ths)->y; }

void 
celestial_ctor(struct celestial_body *ths)
{
  icelestial_ctor (&ths->intf, &celestial_get_x, &celestial_get_y);
  /* ... */  
}

int
detect_collision (struct icelestial_body *lhs, struct icelestial_body *rhs)
{
  double x = lhs->vtable.pget_x(lhs);
  double y = lhs->vtable.pget_y(lhs);
 
  return in_between (rhs->vtable.pget_x(rhs), x - epsilon, x + epsilon) && 
         in_between (rhs->vtable.pget_y(rhs), y - epsilon, y + epsilon);
}

int
foo (void)
{
  struct celestial_body Gallea;
  struct celestial_body Encke;

  celestial_ctor (&Gallea);
  celestial_ctor (&Encke);

  detect_collision (&Gallea.intf, &Encke.intf);

  return 0;
}

