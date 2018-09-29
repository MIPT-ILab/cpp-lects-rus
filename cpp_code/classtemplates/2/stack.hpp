#ifndef STACK_GUARD_
#define STACK_GUARD_

#include <cassert>
#include <utility>

template <typename T>
class Stack 
{
  // state
  struct StackElem 
  {
    T elem;
    StackElem *next;
    StackElem (T e, StackElem *nxt) : elem (e), next (nxt) {}
  };

  struct StackElem *top_;

public:
  // ctors && dtors
  Stack () : top_ (nullptr) {}
  Stack (Stack &&rhs) : top_ (rhs.top_) { rhs.top_ = nullptr; }

  // coersion ctor
  template <typename U>
  Stack (Stack <U> const & rhs);

  // copy ctor
  Stack (Stack <T> const & rhs);

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

  bool empty () const { return (top_ == nullptr); }
  struct StackElem *topptr() const { return top_; }

};

// -- methods

template <typename T>
template <typename U>
Stack<T>::Stack (Stack <U> const & rhs) : top_(nullptr) 
{
  auto nxt = rhs.topptr();
  while (nxt)
    {
      push (nxt->elem); // coerce U --> T
      nxt = nxt->next;
    }
}

template <typename T>
Stack<T>::Stack (Stack <T> const & rhs) : top_(nullptr) 
{
  auto nxt = rhs.top_;
  while (nxt)
    {
      push (nxt->elem);
      nxt = nxt->next;
    }
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

extern template class Stack<int>;
// extern template Stack<double>::Stack (Stack<float> const &rhs);

// --- service declarations

Stack<int> fill_int_stack (int x, int n);
void empty_int_stack (Stack<int> &&s);
Stack<double> coerce_stack (Stack<float> &s);

#endif
