/* LSP */

class Square {
public:
  Square(double x) : m_x(x) {}
  virtual ~Square() {}
  double a(void) { return m_x; }
  virtual double get_sq(void) { return a() * a(); }
protected:
  double m_x;
};

class Rect: public Square {
public:
  Rect(double x, double y) : Square(x), m_y(y) {}
  int b(void) { return m_y; }
  virtual double get_sq(void) { return a() * b(); }
private:
  double m_y;
};

