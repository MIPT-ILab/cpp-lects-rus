#include <iostream>

using std::cout;
using std::cin;

int 
main ()
{
  int n;
  cin >> std::hex >> std::noskipws >> n;
  cout << std::dec << n << std::endl;

  cin.ignore();
  std::dec(cin);

  while (cin >> n)
    {
      cout << n << std::endl;
      cin.ignore();
    }
}

