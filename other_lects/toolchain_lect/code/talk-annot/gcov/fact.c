unsigned
fact (unsigned x)
{
  if (x < 2)
    return 1;

  return x * fact (x-1);
}

