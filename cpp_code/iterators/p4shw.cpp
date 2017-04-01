#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstdlib>

int random_number (void) { return (std::rand () % 20); }

std::vector <int>
bitvise_or (std::vector <int> a, std::vector <int> b)
{
  if ((a.size () == 0) || (b.size () == 0))
    std::cout << "Nothing to or with" << std::endl;
  else if (a.size () != b.size ())
    std::cout << "Can not process arrays of inequal size" << std::endl;
  else
    {
      std::vector <int> ret (a.size ());
      for (std::vector <int>::iterator i = a.begin (), j = b.begin (), k = ret.begin (); i != a.end (); i++, j++, k++)
        *k = *i | *j;
      return ret;
    } 
}

int
main (void)
{
  std::vector<int> v1(10), v2(10), v3;

  std::generate (v1.begin (), v1.end (), random_number);
  std::generate (v2.begin (), v2.end (), random_number);

  v3 = bitvise_or (v1, v2);

  std::cout << std::hex;

  std::copy (v1.begin (), v1.end (), std::ostream_iterator<int> (std::cout, " "));

  std::cout << std::endl;

  std::copy (v2.begin (), v2.end (), std::ostream_iterator<int> (std::cout, " "));

  std::cout << std::endl;
  
  std::copy (v3.begin (), v3.end (), std::ostream_iterator<int> (std::cout, " "));

  std::cout << std::endl;

  return 0;
}

