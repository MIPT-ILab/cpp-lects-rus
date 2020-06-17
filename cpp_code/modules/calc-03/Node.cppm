//------------------------------------------------------------------------------
//
// INode -- main node interfaces, operations enum and ctor functions for nodes
//
//------------------------------------------------------------------------------

export module node;

import <string>;

// node interface
export struct INode {
  virtual int calc() = 0;
  virtual void dump() const = 0;
  virtual ~INode() {}
};

// scope interface
export struct IScope : public INode {
  virtual IScope *push() = 0;
  virtual IScope *resetScope() const = 0;
  virtual void addBranch(INode *branch) = 0;
  virtual INode *access(std::string const &var_name) = 0;
  virtual INode *visible(std::string const &var_name) = 0;
};

// operations
export enum class Ops {
  Plus,
  Minus,
  Assign,
  Greater,
  Less,
  GreaterEq,
  LessEq,
  StdOut,
  StdIn,
  Equal,
  NotEqual,
  Div,
  Mul,
  Mod,
  Not,
  And,
  Or
};

// ctor functions
export INode *make_value(int);
export INode *make_op(INode *l, Ops o, INode *r);
export INode *make_while(INode *o, INode *s);
export INode *make_if(INode *o, INode *s);
export IScope *create_scope();
