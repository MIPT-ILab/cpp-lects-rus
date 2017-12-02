#include <climits>

template <typename T> struct my_numeric_limits;

template <> struct my_numeric_limits<char> {
  static constexpr size_t max() { return CHAR_MAX; }
};

int arr0 [my_numeric_limits<char>::max()];

constexpr size_t MAXSZ = my_numeric_limits<char>::max();
int arr [MAXSZ];

int
main (void)
{
}

