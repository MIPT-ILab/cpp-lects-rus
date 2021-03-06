#include <memory>

#include "myres.h"

using std::auto_ptr;

template <typename T> 
struct Brittle 
{
  T working_, reserve_;
  Brittle (T val) : working_(val), reserve_(working_) {}
};

int
main () 
{
  Brittle<auto_ptr<MyRes>> b (auto_ptr<MyRes>(new MyRes(42, 42.0)));
  if (!b.working_.get())
    cout << "b.working_ empty" << endl;
}