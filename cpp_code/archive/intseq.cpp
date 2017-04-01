#include <utility>
#include <functional>
#include <iostream>

using namespace std;

#define MK_TEST(n) timer_test_##n

int timer_test_1 () { cout << "t1" << endl; }
int timer_test_2 () { cout << "t2" << endl; }
int timer_test_3 () { cout << "t3" << endl; }
int timer_test_4 () { cout << "t4" << endl; }
int timer_test_5 () { cout << "t5" << endl; }

using test_t = int(void);

test_t *tests[] = { timer_test_1, timer_test_2 };
const int ntests = sizeof(tests) / sizeof(test_t*);

template<size_t... index> void
invoke_tests(std::index_sequence<index...>) {
  for (auto i : { index... }) tests[i]();
}

int
main () {
  invoke_tests (std::make_index_sequence<ntests>{});
}
#if 0
template<size_t... index>
constexpr void fU(std::index_sequence<index...>)
{
/*
  for (auto i : { index... }) cout << i << " ";
  cout << endl;
*/
}

int main()
{
  fU(std::make_index_sequence<5>{});
  MK_TEST(5)();
  return 0;
}
#endif
