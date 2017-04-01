#include <iostream>

using std::cout;
using std::endl;

template <template <typename> class Derived, typename Value> 
struct interface 
{
  void do_something(Value v) { static_cast<Derived<Value>*>(this)->do_something(v); }
};

template <typename Value> 
struct derived : public interface <derived, Value> 
{
  void do_something(Value v) { cout << "victory " << v << endl; }
};

typedef interface <derived, int> derived_t;

int
main (void)
{
  derived_t d;
  d.do_something(42);
}


