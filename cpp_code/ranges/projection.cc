#include <iostream>
#include <vector>
#include <string>

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
  for (auto&& name : vname)
    std::cout << name << " ";
  std::cout << std::endl;
  
  ranges::sort(persons, {}, [](auto && n) { return n.age; });
  // or just: std::ranges::sort(persons, {}, &Person::age);

  // note: the same vname view!
  std::cout << "Sorted by age:" << std::endl;  
  for (auto&& name : vname)
    std::cout << name << " ";
  std::cout << std::endl;
}
