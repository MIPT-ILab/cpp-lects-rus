int is_prime(int x) {
  int divisor;

  for (divisor = 3; divisor * divisor < x; ++divisor) 
    if ((x % divisor) == 0)
      return 0;

  return 1;
}

