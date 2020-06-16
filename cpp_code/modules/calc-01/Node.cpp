//------------------------------------------------------------------------------
//
// Node.cpp -- concrete node types implementation
//
//------------------------------------------------------------------------------

#include "Node.hpp"
#include "Symtab.hpp"

Symtab globalTable;

INode *make_value(int v) { return new Value{v}; }
INode *make_op(INode *l, Ops o, INode *r) { return new Op{l, o, r}; }
INode *make_while(INode *o, INode *s) { return new While{o, s}; }
INode *make_if(INode *o, INode *s) { return new If{o, s}; }
IScope *create_scope() { return new Scope{nullptr}; }

// NUMBER
RType Value::calc() { return val; }
void Value::dump() const { std::cout << "Node Value: " << val << std::endl; }

RType Decl::calc() { return val; }
void Decl::dump() const { std::cout << "Node Decl: " << val << std::endl; }
void Decl::SetValue(int Val) { val = Val; }

// SCOPE

RType Scope::calc() {
  for (auto x : branches)
    x->calc();

  return 0;
}
void Scope::dump() const {
  std::cout << "Node Scope: " << std::endl;
  for (auto const x : branches)
    x->dump();
}
IScope *Scope::resetScope() const { return prev_scope; }
void Scope::addBranch(INode *branch) { branches.push_back(branch); }

INode *Scope::access(std::string const &var_name) {
  INode *t = visible(var_name);
  if (t)
    return t;

  INode *d = new Decl;
  globalTable.add(this, var_name, d);
  return d;
}

INode *Scope::visible(std::string const &var_name) {
  INode *f = globalTable.exists(this, var_name);
  if (f)
    return f;
  if (prev_scope)
    f = prev_scope->visible(var_name);
  return f;
}

Scope::~Scope() {
  for (auto x : branches)
    delete x;

  globalTable.free(this);
}

RType Op::calc() {
  int val = 0;
  switch (op) {
  case Ops::Plus:
    if (left == nullptr)
      return 0 + right->calc();
    return left->calc() + right->calc();
    break;
  case Ops::Minus:
    if (left == nullptr)
      return 0 - right->calc();
    return left->calc() - right->calc();
    break;
  case Ops::Greater:
    return left->calc() > right->calc();
    break;
  case Ops::Less:
    return left->calc() < right->calc();
    break;
  case Ops::GreaterEq:
    return left->calc() >= right->calc();
    break;
  case Ops::LessEq:
    return left->calc() <= right->calc();
    break;
  case Ops::Assign:
    val = right->calc();
    static_cast<Decl *>(left)->SetValue(val);
    return val;
    break;
  case Ops::StdOut:
    std::cout << right->calc() << std::endl;
    break;
  case Ops::StdIn:
    std::cin >> val;
    return val;
    break;
  case Ops::Equal:
    return (left->calc() == right->calc());
    break;
  case Ops::NotEqual:
    return (left->calc() != right->calc());
    break;
  case Ops::Not:
    return !static_cast<bool>(right->calc());
    break;
  case Ops::And:
    return left->calc() && right->calc();
    break;
  case Ops::Or:
    return left->calc() || right->calc();
    break;
  case Ops::Div:
    val = right->calc();
    if (!val) {
      std::cout << "Division by zero!" << std::endl;
      exit(1);
    }
    return left->calc() / right->calc();
    break;
  case Ops::Mul:
    return left->calc() * right->calc();
    break;
  case Ops::Mod:
    return left->calc() % right->calc();
    break;
  default:
    return 999;
  }

  return 998;
}

void Op::dump() const {
  std::cout << "Node Op: ";
  int val = 0;
  switch (op) {
  case Ops::Plus:
    std::cout << "Plus" << std::endl;
    if (left == nullptr)
      right->dump();
    else {
      left->dump();
      right->dump();
    }
    break;
  case Ops::Minus:
    std::cout << "Minus" << std::endl;
    if (left == nullptr)
      right->dump();
    else {
      left->dump();
      right->dump();
    }
    break;
  case Ops::Greater:
    std::cout << "Greater" << std::endl;
    left->dump();
    right->dump();
    break;
  case Ops::Less:
    std::cout << "Less" << std::endl;
    left->dump();
    right->dump();
    break;
  case Ops::Assign:
    std::cout << "Assign" << std::endl;
    left->dump();
    right->dump();
    break;
  case Ops::StdOut:
    std::cout << "StdOut" << std::endl;
    right->dump();
    break;
  case Ops::StdIn:
    std::cout << "StdIn" << std::endl;
    break;
  case Ops::Equal:
    std::cout << "Equal" << std::endl;
    left->dump();
    right->dump();
    break;
  }
}
Op::~Op() {
  if (left && typeid(Decl) != typeid(*left))
    delete left;
  if (right && typeid(Decl) != typeid(*right))
    delete right;
}

RType While::calc() {
  while (op->calc())
    scope->calc();

  return 0;
}
void While::dump() const {
  std::cout << "Node While " << std::endl;
  scope->dump();
}
While::~While() {
  if (op && typeid(Decl) != typeid(*op))
    delete op;
  delete scope;
}

RType If::calc() {
  if (op->calc())
    scope->calc();

  return 0;
}
void If::dump() const {
  std::cout << "Node If " << std::endl;
  scope->dump();
}
If::~If() {
  if (op && typeid(Decl) != typeid(*op))
    delete op;
  delete scope;
}