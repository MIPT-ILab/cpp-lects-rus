#include <climits>

template <typename T> struct my_numeric_limits;

template <> struct my_numeric_limits<int> {
  static const int max() { return INT_MAX; }
};

const int MAXSZ = my_numeric_limits<int>::max();
int arr [MAXSZ];

int
main (void)
{
}

