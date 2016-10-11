auto sum_to (int i)
{
  if (i < 2)
    return i; // return type deduced as int
  else
    return sum_to (i-1) + i;  // ok to call it now
}

