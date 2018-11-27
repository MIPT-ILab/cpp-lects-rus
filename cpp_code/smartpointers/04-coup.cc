#include <memory>

#include "myres.h"

using std::unique_ptr;

template <typename T> 
struct Brittle 
{
  T working_, reserve_;
  Brittle (T val) : working_(val), reserve_(working_) {}
};

int
main () 
{
  // CE here
  Brittle<unique_ptr<MyRes>> b (unique_ptr<MyRes>(new MyRes(42, 42.0)));
}