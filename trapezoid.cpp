#include "trapezoid.h"

point::point() {}

point::point(double a, double b) {
  x = a;
  y = b;
}

bool point::operator < (point a) {
  return (x < a.x) || ((x == a.x) && (y < a.y));
}

segment::segment() {}

segment::segment(double a, double b, double c, double d) {
  start = point(a, b);
  end = point(c, d);
  if (end < start) {
    point x = start;
    start = end;
    end = x;
  }
}

double point::projection(segment b) {
  if (x == b.start.x) {
    return b.start.y;
  } else if (x == b.end.x) {
    return b.end.y;
  } else {
    return b.start.y + ((b.end.y - b.start.y) * (x - b.start.x)) / (b.end.x - b.start.x);
  }
}

trapezoid::trapezoid(){};

trapezoid::trapezoid(segment a, segment b, point c, point d) {
  top = a;
  bottom = b;
  left = c;
  right = d;
}

