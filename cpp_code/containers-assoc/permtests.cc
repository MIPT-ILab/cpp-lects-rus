//------------------------------------------------------------------------------
//
// Tests for permutation loops
//
//------------------------------------------------------------------------------

#include <iterator>

#include "idomain.hpp"
#include "permloops.hpp"
#include "perms.hpp"
#include "groups.hpp"

using std::back_inserter;

int
test_loops() {
  cout << "Loop tests" << endl;
  using CD = CharDomain<'a', 'd'>;
  PermLoop<CD> p1 {'a', 'c', 'd'};
  vector<char> vp2 {'d', 'a', 'c'};
  PermLoop<CD> p2(vp2.begin(), vp2.end());
  cout << p1 << " == " << p2 << endl;
  assert(p1 == p2);
  p2.inverse();
  cout << p1 << " != " << p2 << endl;
  assert(p1 != p2);
  assert(p1.smallest() == 'a');
  assert(p1.contains('d'));
  assert(p1.apply('a') == 'c');
  
  vector<CD> initial {'a', 'b', 'c', 'd'};
  vector<CD> permuted {'c', 'b', 'd', 'a'};
  vector<CD> v = initial;
  p1.apply(v.begin(), v.end());
  assert(v == permuted);
  p2.apply(v.begin(), v.end());
  assert(v == initial);
}

int
test_create_loops() {
  using CD = CharDomain<'a', 'd'>;
  vector<PermLoop<CD>> loops1;
  PermLoop<CD> p1 {'a', 'c', 'd'};
  vector<CD> permuted {'c', 'b', 'd', 'a'};
  create_loops(permuted.begin(), permuted.end(), back_inserter(loops1));
  cout << "Loops from [c b d a]: ";
  for (const auto& l : loops1)
    cout << l;
  cout << endl;
  assert (loops1.size() == 2);
  assert (loops1[0].size() == 3);
  assert (loops1[1].size() == 1);
  assert (loops1[0] == p1);

  vector<PermLoop<CD>> loops2;
  vector<CD> unpermuted {'a', 'b', 'c', 'd'};
  create_loops(unpermuted.begin(), unpermuted.end(), back_inserter(loops2));
  cout << "Loops from [a b c d]: ";
  for (const auto& l : loops2)
    cout << l;
  cout << endl;
  assert (loops2.size() == 4);
  assert (loops2[0].size() == 1);
  assert (loops2[1].size() == 1);
  assert (loops2[2].size() == 1);
  assert (loops2[3].size() == 1);

  vector<PermLoop<CD>> loops3;
  vector<CD> shifted {'d', 'a', 'b', 'c'};
  create_loops(shifted.begin(), shifted.end(), back_inserter(loops3));
  cout << "Loops from [d a b c]: ";
  for (const auto& l : loops3)
    cout << l;
  cout << endl;
  assert (loops3.size() == 1);
  assert (loops3[0].size() == 4);

  using UD = UnsignedDomain<1, 9>;
  vector<PermLoop<UD>> loops4;
  vector<UD> numbers {9, 2, 3, 1, 7, 6, 8, 5, 4};
  create_loops(numbers.begin(), numbers.end(), back_inserter(loops4));
  cout << "Loops from [9, 2, 3, 1, 7, 6, 8, 5, 4]: ";
  for (const auto& l : loops4)
    cout << l;
  cout << endl;
  assert (loops4.size() == 5);
  assert (loops4[0].size() == 3);
  assert (loops4[1].size() == 1);
  assert (loops4[2].size() == 1);
  assert (loops4[3].size() == 3);
  assert (loops4[4].size() == 1);
}

int
test_simplify_loops() {
  using UD = UnsignedDomain<1, 3>;
  vector<PermLoop<UD>> in_loops0 {{1, 2},{2, 3}};
  vector<PermLoop<UD>> out_loops0;
  simplify_loops(in_loops0.begin(), in_loops0.end(), back_inserter(out_loops0));
  assert (out_loops0.size() == 1);
  cout << "(1 2)(2 3) = " << out_loops0[0] << endl;

  using UD4 = UnsignedDomain<1, 4>;
  vector<PermLoop<UD4>> in_loops1 {{1, 3, 2}, {1, 2, 4}, {1, 4, 3, 2}};
  vector<PermLoop<UD4>> out_loops1;
  simplify_loops(in_loops1.begin(), in_loops1.end(), back_inserter(out_loops1));
  assert (out_loops1.size() == 3);

  for (const auto& l : out_loops1)
    cout << l;
  cout << endl;

  using CG = CharDomain<'a', 'g'>;

  vector<PermLoop<CG>> in_loops {
    {'a', 'c', 'f', 'g'}, 
    {'b', 'c', 'd'},
    {'a', 'e', 'd'},
    {'f', 'a', 'd', 'e'},
    {'b', 'g', 'f', 'a', 'e'}
  };

  cout << "Loops to simplify: ";
  for (const auto& l : in_loops)
    cout << l;
  cout << endl;

  vector<PermLoop<CG>> out_loops;
  simplify_loops(in_loops.begin(), in_loops.end(), back_inserter(out_loops));

  cout << "Loops were simplified to: ";
  for (const auto& l : out_loops)
    cout << l;
  cout << endl;

  PermLoop<CG> s1 = {'a', 'd' ,'g'};
  PermLoop<CG> s2 = {'b', 'c' ,'e'};
  PermLoop<CG> s3 = {'f'};

  assert(out_loops[0] == s1);
  assert(out_loops[1] == s2);
  assert(out_loops[2] == s3);

}

int
test_simple_perms() {
  cout << "Simple perm tests" << endl;
  using UD3 = UnsignedDomain<1, 3>;

  Permutation<UD3> e;
  Permutation<UD3> g1{{1, 2}};
  Permutation<UD3> g2{{2, 3}};

  cout << "e = " << e << endl;
  cout << "g1 = " << g1 << endl;
  cout << "g2 = " << g2 << endl;

  auto ne = product(e, e);
  assert (ne == e);

  auto n1 = product(e, g1);
  assert (n1 == g1);

  auto b1 = product(n1, g1);
  assert (b1 == e);

  auto n2 = product(e, g2);
  assert (n2 == g2);

  auto b2 = product(n2, g2);
  assert (b2 == e);

  auto n3 = product(n1, g2);
  cout << n1 << " * " << g2 << " = " << n3 << endl;

  auto b3 = product(n3, g2);
  cout << n3 << " * " << g2 << " = " << b3 << endl;
  assert (b3 == g1);

  auto n4 = product(n2, g1);
  cout << n2 << " * " << g1 << " = " << n4 << endl;
  assert (n3 != n4);

  auto b4 = product(n4, g1);
  cout << n4 << " * " << g1 << " = " << b4 << endl;
  assert (b4 == g2);

  auto n5 = product(n4, g2);
  cout << "e * g2 * g1 * g2 = " << n5 << endl;

  auto n6 = product(n3, g1);
  cout << "e * g1 * g2 * g1 = " << n6 << endl;

  assert (n5 == n6);

  using UD5 = UnsignedDomain<1, 5>;

  Permutation<UD5> e6;
  Permutation<UD5> g3{{1, 2},{3, 4, 5}};
  auto g3orig = g3;
  cout << "Permutation: " << g3 << endl;
  vector<UD5> initial {1, 2, 3, 4, 5};
  vector<UD5> permuted {2, 1, 4, 5, 3};
  auto v = initial;
  g3.apply(v.begin(), v.end());
  assert (v == permuted);
  g3.inverse();
  cout << "Inversed permutation: " << g3 << endl;
  g3.apply(v.begin(), v.end());
  assert (v == initial);
  auto p1 = product(g3, g3orig);
  cout << "Product of perm and inverse " << p1 << endl;
  assert (p1 == e6);
  assert (product(g3orig, g3) == p1);
  g3 = g3orig;
  Permutation<UD5> g4({{1, 2, 3},{4, 5}});
  Permutation<UD5> g5({{1, 3},{2, 4, 5}});
  auto p34 = product(g3, g4);
  auto p45 = product(g4, g5);
  cout << g3 << " * " << g4 << " = " << p34 << endl;  
  cout << g4 << " * " << g5 << " = " << p45 << endl;  
  auto px = product(g3, p45);
  auto py = product(p34, g5);
  cout << "g3 * (g4 * g5) = " << px << endl;
  cout << "(g3 * g4) * g5) = " << py << endl;
  assert (px == py);
}

int
test_simple_orbit() {
  using UD5 = UnsignedDomain<1, 5>;

  UD5 celt = 1;
  cout << "Orbit for cyclic group element " << celt << endl;
  vector<Permutation<UD5>> cgens {{{1, 5, 4, 3, 2}}};
  auto corbit = simple_orbit(celt, cgens.begin(), cgens.end());
  cout << "Orbit is [";
  copy(corbit.begin(), corbit.end(), ostream_iterator<UD5>(cout, " "));
  cout << "]" << endl;

  UD5 aelt = 2;
  cout << "Orbit for alternating group element " << aelt << endl;
  vector<Permutation<UD5>> agens {{{1, 2},{3, 4}}, 
                                 {{2, 3},{4, 5}}};
  auto aorbit = simple_orbit(aelt, agens.begin(), agens.end());
  cout << "Orbit is [";
  copy(aorbit.begin(), aorbit.end(), ostream_iterator<UD5>(cout, " "));
  cout << "]" << endl;

  UD5 selt = 3;
  cout << "Orbit for symmetric group element " << selt << endl;
  vector<Permutation<UD5>> sgens {{{1, 2, 3, 4, 5}},
                                  {{1, 2}}};
  auto sorbit = simple_orbit(selt, sgens.begin(), sgens.end());
  cout << "Orbit is [";
  copy(sorbit.begin(), sorbit.end(), ostream_iterator<UD5>(cout, " "));
  cout << "]" << endl;

  UD5 delt = 4;
  cout << "Orbit for direct sum group element " << delt << endl;
  vector<Permutation<UD5>> dgens {{{1, 2}},
                                  {{3, 4, 5}}};
  auto dorbit = orbit2(delt, dgens.begin(), dgens.end());
  cout << "Orbit is [";
  copy(dorbit.begin(), dorbit.end(), ostream_iterator<UD5>(cout, " "));
  cout << "]" << endl;

  UD5 ielt = 5;
  cout << "Orbit for isolated group element " << ielt << endl;
  vector<Permutation<UD5>> igens {{{1, 2, 3, 4}},
                                  {{1, 2}}};
  auto iorbit = simple_orbit(ielt, igens.begin(), igens.end());
  cout << "Orbit is [";
  copy(iorbit.begin(), iorbit.end(), ostream_iterator<UD5>(cout, " "));
  cout << "]" << endl;
}

int
main()
{
  try {
    test_loops();
    test_create_loops();
    test_simplify_loops();
    test_simple_perms();
    test_simple_orbit();
  }
  catch(runtime_error &e) {
    cout << "Failed: " << e.what() << endl;
    exit(-1);
  }
  cout << "Passed" << endl;
}
