// like mpl example for meta lecture
// but with constexpr and standard C++17 only

#include <array>
#include <iostream>
#include <string>
#include <utility>

struct TagEntity {
  bool isValid;
  std::string value;
};

template <int N>
struct ct_ints {
  std::array<int, N> arr_;

  template <int ... Is>
  constexpr ct_ints(std::integer_sequence<int, Is...>) : arr_{Is...} {}

  constexpr int find(int tag) const {
    for(int i = 0; i < N; ++i)
      if (arr_[i] == tag)
        return i;
    return N + 1;
  }
};

template <typename CommonTags>
struct FixMsg {
  static constexpr int CommonTagsCount = CommonTags::size();  

  template<int Tag>
  TagEntity& getTagEntity() {
    constexpr ct_ints<CommonTagsCount> vec(CommonTags{});
    constexpr int idx = vec.find(Tag);
    static_assert(static_cast<int>(idx) < static_cast<int>(CommonTagsCount), 
                  "tag not found");
    return commonTags_[idx];
  }

  std::array<TagEntity, CommonTagsCount> commonTags_;
};

int main() {  
  using MyCommonTags = std::integer_sequence<int, 11, 35, 10914, 10916>;
  FixMsg<MyCommonTags> fixMsg;

#ifndef ERROR  
  auto& tagEntity = fixMsg.getTagEntity<11>();
#else
  auto& tagEntity = fixMsg.getTagEntity<13>();
#endif  
  tagEntity.isValid = true;
  tagEntity.value = "Get tag entity in O(1)";

  std::cout << tagEntity.value << std::endl;
}
