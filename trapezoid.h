#ifndef TRAPEZOID
#define TRAPEZOID

#include <memory>

struct segment;
struct trapezoid;

const double EPS = 1e-12;

struct point {
  point();
  point(double, double);
  
  bool operator < (point);
  bool operator == (point);

  double projection(segment*);
  void set_segment(segment*);
  segment* get_segment();

  double x, y;
  segment* segm;
};

struct segment {
  segment();
  segment(double, double, double, double);
  segment(segment const&) = delete;
  segment(segment&&);
  segment& operator=(segment&&);
  void draw(double, point);

  point start, end;
};

struct trapezoid {
  trapezoid();
  trapezoid(segment *a, segment *b, point c, point d);
  void draw(double, point);

  segment *top, *bottom;
  point left, right;
  trapezoid *right_up = 0, *right_down = 0;
  trapezoid *left_up = 0, *left_down = 0;
};

int left_turn(point, point, point);

#endif 
