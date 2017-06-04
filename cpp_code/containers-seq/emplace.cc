#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;

struct Heavy {
  explicit Heavy (int sz) {
    cout << "Heavy created" << endl;
  }

  Heavy(const Heavy &rhs) {
    cout << "Heavy copy-constructed" << endl;
  }

  Heavy (Heavy &&rhs) noexcept {
    cout << "Heavy move-constructed" << endl;
  }

  Heavy& operator= (const Heavy &rhs) {
    cout << "Heavy copied" << endl;
    return *this;
  }

  Heavy& operator= (Heavy &&rhs) noexcept {
    cout << "Heavy moved" << endl;
    return *this;
  }
};

int
main ()
{
  deque<Heavy> d;

  for (int i = 0; i != 5; ++i)
    d.push_front(Heavy(i));

  for (int i = 0; i != 5; ++i)
    d.emplace_back(i);
}

