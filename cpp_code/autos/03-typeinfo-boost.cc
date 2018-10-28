#include <typeinfo>
#include <iostream>

#include <boost/type_index.hpp>

using std::cout;
using std::endl;
using boost::typeindex::type_id_with_cvr;

struct Empty {};

template <typename T>
void
foo (const T& t) {
  cout << type_id_with_cvr<decltype(t)>().pretty_name() << endl;
}

int
main (void)
{
  const Empty *c;
  foo (c);  
}

