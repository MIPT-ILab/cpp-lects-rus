/* hard inheritance */

class B1 { };
class V1 : public B1 { };
class D1 : virtual public V1 { };
class B2 { };
class B3 { };
class V2 : public B1, public B2 { };
class D2 : virtual public V2, public B3 { };
class M1 { };
class M2 { };
class X : public D1, public D2 {
  M1 m1_;
  M2 m2_;
};

