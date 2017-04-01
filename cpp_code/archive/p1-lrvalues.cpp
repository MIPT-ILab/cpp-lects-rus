int t1 = 0; 
int t2 = 0;
const int t3 = 0;
const int t4 = 0;
int const *t5 = &t3;
int const *t6 = &t4;
int *const t7 = &t1;
int *const t8 = &t2;

int
main (void)
{
  t1 = t2;
  // t3 = t4;
  t5 = t6;
  // t7 = t8;
  return 0;
}
