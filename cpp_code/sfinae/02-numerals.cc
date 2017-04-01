#include <iostream>

using std::cout;
using std::endl;

template <typename T, unsigned int N>
class ArrayFst {
  void do_insertion_sort() { cout << "INSRT" << endl; }
  void do_quick_sort() { cout << "QUICK" << endl; }
public:
  void sort () {
    if (N < 50) do_insertion_sort(); else do_quick_sort();
  }
};


template <int I>
struct Int2Type 
{
  enum { value = I };
  typedef int value_type;
  typedef Int2Type<I> type;
  typedef Int2Type<I+1> next;
  typedef Int2Type<I-1> previous;
};

template <typename T, unsigned int N>
class Array {
  T contents[N];
  enum AlgoType { INSRT, QUICK };
  static const int algo = (N<50) ? INSRT : QUICK;
  void do_sort (Int2Type<INSRT>) { cout << "INSRT" << endl; }
  void do_sort (Int2Type<QUICK>) { cout << "QUICK" << endl; }
public:
  void sort () { do_sort (Int2Type<algo>()); };
};

int
main (void)
{
  ArrayFst <int, 10> af1;
  ArrayFst <int, 100> af2;

  af1.sort();
  af2.sort();

  Array <int, 10> a1;
  Array <int, 100> a2;

  a1.sort();
  a2.sort();
}

