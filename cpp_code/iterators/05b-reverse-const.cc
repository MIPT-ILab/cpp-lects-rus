#include <iostream>
#include <string>
#include <iterator>

using std::advance;
using std::cout;
using std::distance;
using std::endl;
using std::make_reverse_iterator;
using std::reverse_iterator;
using std::string;

template <typename T> struct TD;

int typecheck() 
{
    string s = "Hello, world";

    string::iterator si = s.begin();
    string::const_iterator csi = s.cbegin();
    string::reverse_iterator rsi = s.rbegin();
    string::const_reverse_iterator crsi = s.crbegin();

    //auto xsi = std::make_move_iterator<string::iterator>(csi).base();

    //TD<decltype(si)> t1;
    //TD<decltype(csi)> t2;
    //TD<decltype(rsi)> t3;
    //TD<decltype(crsi)> t4;
    //TD<decltype(xsi)> t5;
}

template <typename Container, typename ConstIterator>
typename Container::iterator 
remove_constness(Container& c, ConstIterator it) {
  return c.erase(it, it);
}

int main()
{
    string s = "Hello, world";

    auto csi = s.cbegin();
    // >Hello, world

    csi += 5;
    // Hello>, world

    auto crsi = make_reverse_iterator(csi);
    // Hello<, world

    // Meyers trick
    auto rsi = s.rbegin();
    advance(rsi, distance<decltype(crsi)>(rsi, crsi));
    *rsi = 'O';

    // Hinant trick do not work for strings
    // auto rsi = remove_constness(s, crsi);

    string rev(crsi, s.crend());
    cout << rev << endl;
}

