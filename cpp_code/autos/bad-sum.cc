auto bad_sum_to (int i)
{
  if (i > 2)
    return bad_sum_to (i-1) + i;
  else
    return i;
}

