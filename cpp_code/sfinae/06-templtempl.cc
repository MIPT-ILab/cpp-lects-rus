#include <vector>

using std::vector;

template <template <typename> class Storage, typename Element>
struct Stack
{
  Storage<Element> m_storage;
  void push(const Element& e) { m_storage.push_back(e); }
  void pop() { m_storage.pop_back(); }
};


int
main (void)
{
  Stack <vector, int> s;  
}



