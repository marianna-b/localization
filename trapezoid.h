#ifndef TRAPEZOID
#define TRAPEZOID

struct segment;
struct trapezoid;

struct point {
  point();
  point(double, double);
  bool operator < (point);
  double projection(segment);

  double x, y;

};

struct segment {
  segment();
  segment(double, double, double, double);
  void draw(double, point);

  point start, end;
};


struct trapezoid {
  trapezoid();
  trapezoid(segment a, segment b, point c, point d);
  void draw(double, point);

  segment top, bottom;
  point left, right;
};

#endif 
