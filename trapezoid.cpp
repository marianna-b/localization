#include "trapezoid.h"
using namespace std;

point::point() {}

point::point(double a, double b) {
  x = a;
  y = b;
}

bool point::operator < (point a) {
  return (x < a.x) || ((x == a.x) && (y < a.y));
}

bool point::operator == (point a) {
  return (x == a.x) && (y == a.y);
}

void point::set_segment(segment* s) {
  segm = s;
}

segment* point::get_segment() {
  return segm;
}

segment::segment() {}

segment::segment(segment&& s)
  : segment(s.start.x, s.start.y, s.end.x, s.end.y)
{}

segment::segment(double a, double b, double c, double d) {
  start = point(a, b);
  end = point(c, d);
  if (end < start) {
    point x = start;
    start = end;
    end = x;
  }
  start.set_segment(this);
  end.set_segment(this);
}

double point::projection(segment* b) {
  if (x == b->start.x) {
    return b->start.y;
  } else if (x == b->end.x) {
    return b->end.y;
  } else {
    return b->start.y + ((b->end.y - b->start.y) * (x - b->start.x)) / (b->end.x - b->start.x);
  }
}

trapezoid::trapezoid(){};

trapezoid::trapezoid(segment* a, segment* b, point c, point d) {
  top = a;
  bottom = b;
  left = c;
  right = d;
}

int left_turn(point a, point b, point c) {
  double x1 = b.x - a.x;
  double y2 = c.y - a.y;
  double x2 = c.x - a.x;
  double y1 = b.y - a.y;
  double res = x1 * y2 - x2 * y1; 
  if (res > 0.0)
    return 1;
  if (0.0 > res)
    return -1;
  return 0;
}
