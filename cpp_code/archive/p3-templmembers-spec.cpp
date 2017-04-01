#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Data  
{
public:
  template <typename T>
  T read() const
  {
    T result = T();
    return result;
  }
};

template <typename T>  
class DataReader  
{
  const T& source_;
public:

  DataReader(const T& s): source_(s) {}

  template <typename R>
  R read() const
  {
    R foo = source_.template read<R>();
    /* ... processing here ... */
    return foo;
  }
  
};

template <>
template <>
std::string DataReader<Data>::read() const
{
  std::string foo = "";
  return foo;
}

int 
main ()
{
  Data d;
  DataReader<Data> reader(d);

  auto myval = reader.read<int>();
  cout << myval << endl; 
} 

