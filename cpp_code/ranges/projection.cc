#include <iostream>
#include <string>
#include <vector>

#include "myranges.hpp"

struct Person {
  std::string name, address;
  int age, height, weight;
};

int main() {
  std::vector<Person> persons = {
#include "persons.inl"
  };

  std::cout << "Unsorted:" << std::endl;
  auto vname = persons | ranges::views::transform(&Person::name);
  for (auto &&name : vname)
    std::cout << name << " ";
  std::cout << std::endl;

  ranges::sort(persons, {}, [](auto &&n) { return n.age; });
  // or just: std::ranges::sort(persons, {}, &Person::age);

  // note: the same vname view!
  std::cout << "Sorted by age:" << std::endl;
  for (auto &&name : vname)
    std::cout << name << " ";
  std::cout << std::endl;

  std::vector<int> dblages;
  ranges::transform(
      persons, ranges::back_inserter(dblages), [](int age) { return age * 2; },
      &Person::age);
  for (auto &&elt : dblages)
    std::cout << elt << " ";
  std::cout << std::endl;
}
