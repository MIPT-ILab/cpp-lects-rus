int main()
{
  int *p = (int *)0xDEADBEEF; /* Invalid address */
  *p = 5;
}

