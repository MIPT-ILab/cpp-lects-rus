#include <utility>

#include "myres.h"
#include "uraii.h"

using std::move;

int
buz (URAIIPtr<MyRes> p) 
{
  p->use();
} // p will be destroyed here

int 
scope_safe (int x, double y) 
{
  URAIIPtr<MyRes> ptr(new MyRes(x, y));

  ptr->use();

  if (x > 3) 
    buz(move(ptr));

  return 0;
}

int
main()
{
  scope_safe(2, 1.0); // OK
  scope_safe(4, 1.0); // OK
}
