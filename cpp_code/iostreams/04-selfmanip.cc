#include <iosfwd>
#include <iostream>

using namespace std;

inline int geti() { 
    static int i = ios_base::xalloc();
    return i;
}

ostream& add_one(ostream& os) { os.iword(geti()) = 1; return os; } 
ostream& add_none(ostream& os) { os.iword(geti()) = 0; return os; }

struct my_num_put : num_put<char> {
    iter_type 
    do_put(iter_type s, ios_base& f, char_type fill, long v) const { 
        return num_put<char>::do_put(s, f, fill, v + f.iword(geti())); 
    } 

    iter_type 
    do_put(iter_type s, ios_base& f, char_type fill, unsigned long v) const { 
        return num_put<char>::do_put(s, f, fill, v + f.iword(geti())); 
    } 
}; 

int main() {
    // outputs: 11121011
    cout.imbue(locale(locale(),new my_num_put));
    cout << add_one << 10 << " " << 11 << "\n"
         << add_none << 10 << " " << 11 << endl;
}

