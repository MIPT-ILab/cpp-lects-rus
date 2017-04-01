class Shape {
public:
  enum ShapeColor {Red, Green, Blue };
  virtual void draw( ShapeColor cl = Red) const = 0;
};

class Rectangle : public Shape {
public:
  virtual void draw( ShapeColor cl = Green) const;
};

int drawShape(const  Shape &shape)
{
  shape.draw();
}

int main(void)
{
  Rectangle rc;
  drawShape(rc);
}

