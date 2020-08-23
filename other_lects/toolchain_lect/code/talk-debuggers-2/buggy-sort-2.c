#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

// sort function: also buggy?

void 
sort (long *arr, unsigned n) 
{
  int i  = 0;
  bool sorted;

  do 
    {
      sorted = true;
      for (i = 0; i < (n - 1); i++) 
        {
          long *item_one = &arr[i];
          long *item_two = &arr[i+1];
          long swap_store;

          if (*item_one <= *item_two)
            continue;
 
          sorted = false;
          swap_store = *item_two;
          *item_two = *item_one;
          *item_one = swap_store;
        }
    } 
  while (!sorted);
}

void
out_array(long *arr, unsigned n) 
{
  int i;

  printf ("[");
  for (i = 0; i < (n - 1); i++)
    printf ("%ld, ", arr[i]);
  printf ("%ld]\n", arr[n - 1]);
}


// caller

int main()
{
  long array[32];
  int i;  

  srand (time(NULL));
  for (i = 0; i < rand() % sizeof array; i++)
    array[i] = rand();

#ifdef OUTARR
  out_array (array, 32);
#endif

  sort (array, 32);

#ifdef OUTARR
  out_array (array, 32);
#endif

  return 0;
}

