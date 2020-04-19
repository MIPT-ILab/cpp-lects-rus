// g++ -I"C:\Users\kvladimi\Downloads\MinGW\include" fusionprog.cc
// via https://www.youtube.com/watch?v=6V73Q7ULFi0

#include <iostream>
#include <cmath>
#include <tuple>
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/functional.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/fusion/support.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

using namespace boost;

struct pythagoras {
  typedef double result_type;
  template<typename T>
  double operator()(double acc, T const & axis) const {
    double d = fusion::at_c<0>(axis) - fusion::at_c<1>(axis);
    return acc + d * d;
  }
};

template <typename P1, typename P2>
double pydist(P1 p1, P2 p2) {
  typedef fusion::vector<P1&, P2&> zip_t;
  double accumulated = fusion::fold(fusion::zip_view<zip_t>(zip_t(p1, p2)), 0, pythagoras());
  return sqrt(accumulated);
}

struct mypoint {
  double x = 0.0, y = 0.0;
  mypoint() = default;
  mypoint(double x, double y): x(x), y(y) {}
};

BOOST_FUSION_ADAPT_STRUCT(
  mypoint,
  (double, x)
  (double, y)
);

int main() {
  typedef std::tuple<int,int> point_2d_t;
  point_2d_t a2(2, 2);
  point_2d_t b2(4, 4);
  double d2 = pydist(a2, b2);

  typedef fusion::tuple<int,int,int> point_3d_t;
  point_3d_t a3(2, 2, 2);
  point_3d_t b3(4, 4, 4);
  double d3 = pydist(a3, b3);
  
  mypoint a(2, 2);
  mypoint b(4, 4);
  double d = pydist(a, b);
  
  std::cout << d2 << " " << d3 << " " << d << std::endl;
}