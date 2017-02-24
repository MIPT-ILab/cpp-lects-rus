#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int
main ()
{
  int num;
  string mystr;

  cout << "Please enter a number: " << "\n";
  cin >> num;
  cout << "Your number is: " << num << "\n";
  cout << "Please enter your name: \n";
  // cin.ignore();
  getline (cin, mystr);
}

