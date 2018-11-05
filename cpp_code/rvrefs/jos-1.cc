#include <string>

class TwoStr {
  string a_;
  string b_;  
public:
  TwoStr(string &a, string &b) : a_(a), b_(b) {}
};

TwoStr v0("One", "Two");