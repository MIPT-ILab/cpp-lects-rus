#include <iostream>
#include <memory>
#include <unordered_map>

#include "myres_idx.h"

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::unordered_map;
using std::weak_ptr;

template <typename T>
shared_ptr<T> createObject(int);

template <>
shared_ptr<MyRes> createObject<MyRes>(int idx)
{
  return make_shared<MyRes>(idx);
}

template <typename T> 
shared_ptr<T> getObject(int id) {
  static unordered_map<int, weak_ptr<T>> cache;
  auto result = cache[id].lock();
  if (!result) 
    cache[id] = result = createObject<T>(id); 
  return result;
}

void foo()
{
  cout << "--- foo ---" << endl;
  auto y = getObject<MyRes>(1);
  auto z = getObject<MyRes>(2);

  y->use();
  z->use();
}

void bar()
{
  cout << "--- bar ---" << endl;
  auto y = getObject<MyRes>(1);
  auto z = getObject<MyRes>(2);

  y->use();
  z->use();
}

int
main ()
{
  auto x = getObject<MyRes>(1);
  x->use();
  foo();
  bar();
}

