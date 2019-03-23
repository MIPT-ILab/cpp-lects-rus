float
foo (float f1, float f2) {
  float ftmp;
  ftmp = f1 / 3.0;
  f1 = 1.0 - f1;
  f1 = f2 * f1;
  f2 = f1 + ftmp;
  return f2; 
}

