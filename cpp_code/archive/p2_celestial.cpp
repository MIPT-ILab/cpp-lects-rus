struct ICelestialBody
{
  virtual double get_x () const = 0;
  virtual double get_y () const = 0;
  virtual int move (double dt) = 0;
  virtual int apply_force (double f, double dt) = 0;
};

class CelestialBody: public ICelestialBody
{
  double x, y;
  double vx, vy;
  double m;
public:
/* ... */
/* ICelestialBody implementation */
  double get_x () const { return x; }
  double get_y () const { return y; }
  int move (double dt); 
  int apply_force (double f, double dt);
/* ... */
};

class Planet: public ICelestialBody
{
  double x, y;
  double vx, vy;
  double m;
  double r;
public:
/* ... */
/* ICelestialBody implementation */
  double get_x () const { return x; }
  double get_y () const { return y; }
  int move (double dt);
  int apply_force (double f, double dt);
  int detect_collision (const ICelestialBody &rhs) const;
};

int CelestialBody::move (double dt) {}
int CelestialBody::apply_force (double f, double dt) {}
int Planet::move (double dt) {}
int Planet::apply_force (double f, double dt) {}

int 
in_between (double x, double ymin, double ymax)
{
  return (x <= ymax) && (x >= ymin);
}

int 
Planet::detect_collision (const ICelestialBody &rhs) const
{
  return in_between (rhs.get_x(), x - r, x + r) && 
         in_between (rhs.get_y(), y - r, y + r);
}

