#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/size.hpp>

namespace mpl = boost::mpl;

template<bool ... Ts> 
struct all_true {  
  using typevec = mpl::vector_c<bool, Ts...>;
  static constexpr bool value = !mpl::contains<typevec, mpl::integral_c<bool, false>>::type::value;
};

