#ifndef STACK_GUARD_
#define STACK_GUARD_

#include <cassert>
#include <utility>

template <typename T>
class Stack 
{
public:
  // ctors && dtors
  Stack () : top_ (nullptr) {}
  Stack (Stack &&rhs) : top_ (rhs.top_) { rhs.top_ = nullptr; }
  Stack (const Stack &) = delete;
  ~Stack ();
public:
  // operators
  Stack & operator= (const Stack &) = delete;
  void operator= (Stack &&rhs);    
public:
  // modifiers
  void push (const T& elem);
  void pop ();
public:
  // selectors
  T top () const 
  { 
    assert (top_ != nullptr);
    return top_->elem; 
  }

  bool empty () const { return (top_ != nullptr); }
private:
  // state
  struct StackElem 
  {
    T elem;
    StackElem *next;
    StackElem (T e, StackElem *nxt) : elem (e), next (nxt) {}
  } *top_;
};

// -- methods

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

template <typename T>
void Stack<T>::operator= (Stack<T> &&rhs)
{
  top_ = rhs.top_;
  rhs.top_ = nullptr;
}

template <typename T>
void Stack<T>::push (const T& elem)
{
  StackElem *newelem = new StackElem (elem, top_);
  top_ = newelem;
}

template <typename T>
void Stack<T>::pop (void)
{
  if (nullptr == top_)
    return;
  StackElem *topelem = top_;
  top_ = top_->next;
  delete topelem;
}

// --- service declarations

Stack<int> fill_int_stack (int x, int n);
void empty_int_stack (Stack<int> &&s);

#endif
