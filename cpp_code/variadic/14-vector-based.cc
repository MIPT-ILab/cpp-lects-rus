#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::move;

int main ()
{
  vector<int> v = {1, 42, 53, 104};
  int t = move(v[2]);
  v[2] = move(v[0]);
  v[0] = move(v[1]);
  v[1] = move(v[3]);
  v[3] = move(t);
  
  // tie (z, x, w, y) = make_tuple (x, y, z, w);
  cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
}

