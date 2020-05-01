template <int N> 
struct Danger 
{
  typedef char block[N]; 
}; 

template <typename T, int N> 
struct Tricky 
{
  void test_lazyness() { 
    Danger<N> no_boom_yet; 
  }
}; 

int main() {
  Tricky<int, -2> ok;
  // ok.test_lazyness();
}

