#include <iostream>
#include <iterator>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdlib>

using namespace std;

/* prefer constants to defines */
const int N = 10;

/* function generator: */
int RandomNumber (void) { return (std::rand() % 20); }

/* less than class */
template <typename T> 
class less_than_X
{
public:
  less_than_X(T x): m_x(x) {}

  bool operator() (const T &x) const
    {
      return (x < m_x);
    }
private:
  T m_x;
};

int main() {
  
  vector<int> v1(N), v2;
  less_than_X<int> pred(10); /* less than 10 instance */

  /* prefer generators to immediate fill */
  generate (v1.begin(), v1.end(), RandomNumber);

  /* some output to look at v1 */
  copy(v1.begin(), v1.end(), std::ostream_iterator<int>(cout, " "));
  cout << std::endl;

  remove_copy_if(v1.begin(), v1.end(), inserter(v2,v2.end()), pred);

  /* some output to be sure v2 contain more than 10 */
  copy(v2.begin(), v2.end(), std::ostream_iterator<int>(cout, " "));
  cout << std::endl;

  return 0;
}
