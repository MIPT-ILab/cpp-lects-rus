int foo();
int bar();

float 
use (float x) {
  return x * x;
}

int
main ()
{
  return (foo() == bar()) ? 0 : 1;
}

