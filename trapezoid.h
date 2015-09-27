#ifndef TRAPEZOID
#define TRAPEZOID

struct segment;
struct trapezoid;

struct point {
  point();
  point(int, int);
  bool operator < (point);
  int projection(segment);

private:
  int x, y;

  friend segment;
  friend trapezoid;
};

struct segment {
  segment();
  segment(int, int, int, int);
  void draw();

private:
  point start, end;
  friend point;
  friend trapezoid;
};


struct trapezoid {
  trapezoid(segment a, segment b, point c, point d);
  void draw();

private:
  segment top, bottom;
  point left, right;
  trapezoid *up, *down, *next, *prev;
  friend point;
  friend segment;
};

#endif 
