
template<typename T> typename T::ElementT 
at (T const& a, int i)
{
  return a[i];
}

#if defined(CORR)

template<typename T> 
auto at (T const& a, int i) -> decltype(a[i])
{
  return a[i];
}

#endif

int f (int *p) 
{ 
  return at (p, 7); 
}

int
main ()
{
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  f (a);
}

