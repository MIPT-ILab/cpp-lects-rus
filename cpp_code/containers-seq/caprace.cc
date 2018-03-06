#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void
caprace(size_t sz) {
  vector<size_t> v;
  size_t step = 1;
  for (size_t x = 0; x < sz; x += step) {
    v.insert(v.end(), step, 0);
    cout << "size:\t" << v.size() << "\tcapacity:\t" << v.capacity() << endl;
    step = v.capacity() / 3 + 1;
  }
}

int
main ()
{
  caprace (500);
}
