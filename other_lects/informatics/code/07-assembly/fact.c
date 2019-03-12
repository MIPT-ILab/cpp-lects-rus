int fact(int x) {
  int acc = 1;

  if (x < 2)
    return x;

  while (x > 0) {
    acc = acc * x;
    x -= 1;   
  }
  
  return acc;
}
