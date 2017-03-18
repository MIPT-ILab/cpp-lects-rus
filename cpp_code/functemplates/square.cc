template<class T>
T square(T n)
{
  return n * n;
}

int
main ()
{
  int x = square (3);
  float y = square<float> (3.0);
  return 0;
}

