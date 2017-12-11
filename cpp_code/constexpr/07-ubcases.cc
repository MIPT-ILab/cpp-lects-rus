template <typename FwdIt, typename Value>
constexpr FwdIt static_find (FwdIt it, FwdIt fin, Value v) 
{
  while ((v != *it) && (it != fin))
    ++it;
  return it;  
}

constexpr bool test_static_find() {
  int a[] = {1}; 
  return ((a + 1) == static_find(a, a + 1, 4));
}

int
main ()
{
  constexpr bool b = test_static_find();

  return (b == true) ? 1 : 0;
}

