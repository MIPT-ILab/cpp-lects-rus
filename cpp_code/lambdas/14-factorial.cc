#include <functional>
#include <iostream>

using std::function;
using std::cout;
using std::endl;

int main ()
{
  function<int (int)> factorial = [&] (int i) { 
    return (i == 1) ? 1 : i * factorial(i - 1); 
  };

  cout << factorial(5) << endl;

}


