#include <cassert>
#include "myres.h"
#include "sraii.h"

int 
naive (int x, double y) 
{
  MyRes *ptr = new MyRes(x, y);

  ptr->use();

  if (x > 3) 
    {
      delete ptr;
      return -1;
    }

  delete ptr; 
  return 0;
}

int 
scoped (int x, double y) 
{
  SRAIIPtr<MyRes> ptr(new MyRes(x, y));

  ptr->use();

  if (x > 3) 
    return -1;

  return 0;
}

int
main ()
{
  cout << "--- naive ---" << endl;
  assert(0 == naive (2, 1.0));
  assert(-1 == naive (4, 1.0));
  cout << "--- scoped ---" << endl;
  assert(0 == scoped (2, 1.0));
  assert(-1 == scoped (4, 1.0));
}

