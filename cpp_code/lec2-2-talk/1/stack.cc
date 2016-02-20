#include "stack.hpp"

// explicit POI
template class Stack<int>;

// little more tricky, yeah?
template Stack<double>::Stack (Stack<float> const &rhs);


