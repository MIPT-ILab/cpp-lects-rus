// optimization attempt

template<bool... Args> struct all_true;

template<bool B1> struct all_true<B1> {
  static constexpr bool value = B1;
};

template<bool B1, bool B2>
struct all_true<B1, B2> {
  static constexpr bool value = B1 && B2;
};

template<bool B1, bool B2, bool B3, bool... Bn>
struct all_true<B1, B2, B3, Bn...> {
  static constexpr bool value = B1 && B2 && B3 && all_true<Bn...>::value;
};

template<bool B1, bool B2, bool B3, 
         bool B4, bool B5, bool B6, 
         bool... Bn>
struct all_true<B1, B2, B3, 
                B4, B5, B6, 
                Bn...> {
  static constexpr bool value = B1 && B2 && B3 && B4 && B5 && B6 && all_true<Bn...>::value;
};
