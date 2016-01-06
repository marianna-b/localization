#ifndef TRAPEZOID
#define TRAPEZOID

#include <memory>

struct segment;
struct trapezoid;

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
  void draw(double, point);

  point start, end;
};

struct trapezoid {
  trapezoid();
  trapezoid(segment *a, segment *b, point c, point d);
  void draw(double, point);

  segment *top, *bottom;
  point left, right;
  trapezoid *right_up, *right_down;
  trapezoid *left_up, *left_down;
};

int left_turn(point, point, point);

#endif 
