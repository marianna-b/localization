#include <trapezoid.h>

point::point() {
  x = y = 0;
}

point::point(int a, int b) {
  x = a;
  y = b;
}

bool point::operator < (point a) {
  return (x < a.x) || ((x == a.x) && (y < a.y));
}

segment::segment() {
  start = point();
  end = point();
}

segment::segment(int a, int b, int c, int d) {
  start = point(a, b);
  end = point(c, d);
  if (end < start) {
    point x = start;
    start = end;
    end = x;
  }
}

int point::projection(segment b) {
  if (x == b.start.x) {
    return b.start.y;
  } else if (x == b.end.x) {
    return b.end.y;
  } else {
    return b.start.y + ((b.end.y - b.start.y) * (x - b.start.x)) / (b.end.x - b.start.x);
  }
}

trapezoid::trapezoid(segment a, segment b, point c, point d) {
  top = a;
  bottom = b;
  left = c;
  right = d;
}

