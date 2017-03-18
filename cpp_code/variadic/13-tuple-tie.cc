#include <iostream>
#include <tuple>

using std::cout;
using std::endl;
using std::tie;
using std::make_tuple;

int main ()
{
  int x = 1, y = 42, z = 53, w = 104;
  tie (z, x, w, y) = make_tuple (x, y, z, w);
  cout << x << " " << y << " " << z << " " << w << endl;
}

