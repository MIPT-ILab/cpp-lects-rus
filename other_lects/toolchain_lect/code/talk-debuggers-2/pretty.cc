#include <map>
#include <utility>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    std::map<int,int> m;
    m.insert(std::make_pair(0, 0));
    m.insert(std::make_pair(1, -1));
    m.insert(std::make_pair(2, -2));
}

