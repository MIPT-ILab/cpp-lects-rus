#include <map>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::map;
using std::string;

int
main () {
  map<int,string> m1 = {{1, "sator"}, {2, "tenet"}, {3, "nothing"}};
  auto extval = m1.extract(3);

  cout << extval.key() << endl;

  map<int,string> m2 = {{2, "nothing"}, {3, "arepo"}, {4, "opera"}, {5, "rotas"}};
  m1.merge(m2);

  for (auto p : m1)
    cout << p.second << endl;
}