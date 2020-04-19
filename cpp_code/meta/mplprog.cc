// g++ mplprog.cc -I"C:\Users\kvladimi\Downloads\MinGW\include"

#include <iostream>
#include <array>
#include <string>
#include <unordered_set>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/size.hpp>

using namespace std;
using namespace boost;

struct TagEntity {
  bool isValid;
  std::string value;
};

template <typename CommonTags>
struct FixMsg {
  enum { CommonTagsCount = mpl::size<CommonTags>::type::value };

  // convert tag to index in compile time
  template<int Tag>
  struct index {
    enum { value = mpl::find<CommonTags, mpl::integral_c<int, Tag>>::type::pos::value };
    static_assert(static_cast<int>(value) < static_cast<int>(CommonTagsCount), 
                  "tag not found");
  };
  
  template<int Tag>
  TagEntity& getTagEntity() {
    int idx = index<Tag>::value;
    return commonTags_[idx];
  }

  std::array<TagEntity, CommonTagsCount> commonTags_;
};


int main(int argc, char** argv) {
  using MyCommonTags = mpl::vector_c<int, 11, 35, 10914, 10916>;

  FixMsg<MyCommonTags> fixMsg;

#ifndef ERROR  
  auto& tagEntity = fixMsg.getTagEntity<11>();
#else
  auto& tagEntity = fixMsg.getTagEntity<13>();
#endif  

  tagEntity.isValid = true;
  tagEntity.value = "Get tag entity in O(1)";

  cout << tagEntity.value << endl;
}