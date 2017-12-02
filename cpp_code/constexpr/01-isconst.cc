#include <climits>

template <typename T> struct my_numeric_limits;

template <> struct my_numeric_limits<char> {
  static const int max() { return CHAR_MAX; }
};

int arr[my_numeric_limits<char>::max()];

// this is not an option too:
// const int MAXSZ = my_numeric_limits<char>::max();
// char arr [MAXSZ];

int
main (void)
{
}

