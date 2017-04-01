template <typename T> struct Vector {};
template <template <typename> class Storage, 
        typename Element> struct Stack {};
template <template <template <typename> typename, typename> typename Stack, 
        template <typename> class Storage, 
        typename Element> struct SList {};

int
main (void)
{
  Vector <int> v;
  Stack <Vector, int> s;
  SList <Stack, Vector, int> a;
}



