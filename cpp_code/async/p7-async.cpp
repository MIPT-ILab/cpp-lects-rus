#include <future>
#include <iostream>

class EquationSolver
{
public:
  void runMultiThread ();
private:
  int calculate (int from, int to);  
};

int 
EquationSolver::calculate (int from, int to)
{
  return (from + to) / 2;
}

void 
EquationSolver::runMultiThread()
{
  std::future<int> f1 = std::async (&EquationSolver::calculate, this,  0, 10);
  std::future<int> f2 = std::async (&EquationSolver::calculate, this, 11, 20);

  int res1 = f1.get ();
  int res2 = f2.get ();

  std::cout << res1 << " " << res2 << std::endl;
}

int
main (void)
{
  EquationSolver t;
  t.runMultiThread ();
  return 0;
}

