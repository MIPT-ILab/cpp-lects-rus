#include <cstdio>
#include <cstdlib>

using namespace std;

template <typename T>
class Stack {
public:
  Stack() : m_top(NULL) {}
  void push(const T& elem);
  void pop();
  T top() const { return m_top->elem; }
private:
  struct StackElem {
    T elem;
    StackElem *next;
  } *m_top;
}; 

template <typename T>
void Stack<T>::push(const T& elem)
{
  StackElem *newelem = new StackElem;
  newelem->elem = elem;
  newelem->next = m_top;
  m_top = newelem;
}

template <typename T>
void Stack<T>::pop(void)
{
  if (NULL == m_top)
    return;
  StackElem *topelem = m_top;
  m_top = m_top->next;
  delete topelem;
}

int main (void)
{
  Stack <int> intstack;
  Stack <double> dblstack;
  intstack.push(2);
  dblstack.push(2.0);
  printf("top1 = %d, top2 = %lf\n", intstack.top(), dblstack.top());
  intstack.push(3);
  dblstack.push(3.0);
  printf("top1 = %d, top2 = %lf\n", intstack.top(), dblstack.top());
  intstack.pop();
  dblstack.pop();
  printf("top1 = %d, top2 = %lf\n", intstack.top(), dblstack.top());
  return 0;
}
