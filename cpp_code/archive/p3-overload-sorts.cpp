#include <iostream>

using std::cout;
using std::endl;

int 
sortpp (int arr[], int size)
{
  cout << "for int" << endl;
}

template <typename T>
int sortpp (T* arr[], int size) 
{
  cout << "for ptrs" << endl;
}

template <typename T>
int sortpp (T arr[], int size)
{
  cout << "for any T" << endl;
}

int
main ()
{
  int ai[] = {1, 2, 3};
  double ad[] = {1.0, 2.0, 3.0};
  double *adp[] = {&ad[0], &ad[1], &ad[2]};

  sortpp (ai, 3);
  sortpp (ad, 3);
  sortpp (adp, 3);
  sortpp<int> (ai, 3);
  sortpp<double*> (adp, 3);

  return 0;
}
