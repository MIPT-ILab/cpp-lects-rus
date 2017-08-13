# include <iostream>
# include <typeinfo>
# include <boost/preprocessor/list/for_each.hpp>
# include <boost/preprocessor/tuple/to_list.hpp>

# define BUILTIN_TYPES \
   BOOST_PP_TUPLE_TO_LIST( \
      13, \
      ( \
         bool, \
         char, signed char, unsigned char, \
         unsigned short, short, \
         int, unsigned, \
         long, unsigned long, \
         float, \
         double, long double \
      ) \
   )

# define CATCH(R, _, T) \
   catch (T t) { \
      std::cerr << "Caught an " << typeid(t).name() << " = " << t << std::endl; \
   }

int 
main() 
{
  try 
    {
      throw 10;
    }
  BOOST_PP_LIST_FOR_EACH(CATCH, _, BUILTIN_TYPES)
  return 0;
}
