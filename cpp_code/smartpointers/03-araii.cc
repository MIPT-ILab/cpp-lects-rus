#include "myres.h"
#include "sraii.h"
#include "araii.h"

int
bar (MyRes *p) {
  p->use();
  delete p;
}

int 
scope_leak (int x, double y) 
{
  SRAIIPtr<MyRes> ptr(new MyRes(x, y));

  ptr->use();

  if (x > 3) 
    bar(ptr.get());

  return 0;
}

int
buz (ARAIIPtr<MyRes> p) {
  p->use();
} // p will be destroyed here

int 
scope_safe (int x, double y) 
{
  ARAIIPtr<MyRes> ptr(new MyRes(x, y));

  ptr->use();

  if (x > 3) 
    buz(ptr);

  return 0;
}

int
main()
{
  scope_leak(2, 1.0); // OK
  // scope_leak(4, 1.0); // FAIL
  scope_safe(2, 1.0); // OK
  scope_safe(4, 1.0); // OK
}
