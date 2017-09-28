#include <iostream>

using std::cout;
using std::endl;

template<typename T> 
struct container 
{
  container(T t) { cout << "Ctored from arg" << endl; }
};

int
main ()
{
  container c(7);
  auto c1 = container(7);
  auto c2 = new container(7); 
}

