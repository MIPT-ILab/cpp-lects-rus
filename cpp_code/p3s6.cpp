template <int N> 
class Danger { 
public: 
  typedef char block[N];  // would fail for N<=0 
}; 

template <typename T, int N> 
class Tricky { 
public: 
  void test_lazyness() { 
      Danger<N> no_boom_yet; 
  }
};

int main(void) 
{ 
  Tricky<int, -2> ok;
  return 0;
} 

