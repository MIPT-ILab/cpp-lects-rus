int fact(int x) {
  int acc = x;
  x -= 1;   
  if (x < 2) goto ret;
loop:
    acc = acc * x;
    x -= 1;   
  if (x > 0) goto loop;  
ret:
  return acc;
}
