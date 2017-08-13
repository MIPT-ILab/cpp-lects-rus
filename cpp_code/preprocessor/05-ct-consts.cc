struct S {
  static const int a;
};

const int x = S::a;
const int y = S::a;

const int S::a = 37; 

int foo () {
   const int z = x;
   static const int w = y;
   return w;
}
 

