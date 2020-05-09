#include <boost/hana/assert.hpp>
#include <boost/hana/contains.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/front.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>

namespace hana = boost::hana;

template<bool ... Ts> 
struct all_true {  
  static constexpr bool value = !hana::contains(hana::tuple_c<bool, Ts...>, false);
};
