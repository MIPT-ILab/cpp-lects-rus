#include <iostream>
#include <cstring>

using namespace std;

class Heavy
{
  int n;
  int *t;
public:
  Heavy (int sz) : n(sz), t(new int[n]) {
    cout << "Heavy created" << endl;
  }

  Heavy(const Heavy &rhs) : n(rhs.n), t(new int[n]) {
    cout << "Heavy copied" << endl;
    memcpy (t, rhs.t, n*sizeof(int));
  }

  ~Heavy () {
    cout << "Heavy destroyed" << endl;
    delete [] t;
  }
};

template <typename T>
class Stack
{
  struct StackElem
  {
    T elem;
    StackElem *next;
    StackElem (T e, StackElem *nxt) : elem (e), next (nxt) {}
  };

  struct StackElem *top_;  

public:
  Stack () : top_ (nullptr) {}
  Stack (const Stack<T>& rhs) = delete;
  ~Stack ();

  Stack<T>& operator= (const Stack<T>& rhs) = delete;

  void push_back (const T&); 
};

template <typename T>
void Stack<T>::push_back (const T& elem)
{
  StackElem *newelem = new StackElem (elem, top_);
  top_ = newelem;
}

template <typename T>
Stack<T>::~Stack ()
{
  struct StackElem *nxt = top_;
  while (nxt != nullptr)
    {
      struct StackElem *tmp = nxt->next;
      delete nxt;
      nxt = tmp;
    }
  top_ = nullptr;
}

int
main (void)
{
  Stack<Heavy> s;
  for (int i = 0; i != 10; ++i)
    {
       cout << endl << "next" << endl;
       s.push_back(Heavy(100));
    }
  cout << endl << "we are done\n" << endl;
} 
