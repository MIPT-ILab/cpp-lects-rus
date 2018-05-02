#include <map>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::map;
using std::string;

int
main () {
  map<int,string> m;
  m.insert({1, "sator"});
  m.insert({1, "nothing"});
  m.emplace(2, "arepo");
  m[3] = "tenet";
  m.try_emplace(4, "opera verdi", 5); // string(char*, count)
  auto it = m.lower_bound(5);
  if (it == m.end() || it->first != 5)
    m.emplace_hint(it, 5, "rotas");  

  for (auto p : m)
    cout << p.second << endl;
}

