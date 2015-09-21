#include <iostream>
#include <cstdio>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/x.H> 

using namespace std;

const int WIDTH = 1300;
const int HEIGHT = 750;


struct point {
  int x, y;

  point() {
    x = y = 0;
  }

  point(int a, int b) {
    x = a;
    y = b;
  }

  bool operator < (point a) {
    return (x < a.x) || ((x == a.x) && (y < a.y));
  }
};

struct segment {
  point start, end;

  segment() {
    start = point();
    end = point();
  }

  segment(int a, int b, int c, int d) {
    start = point(a, b);
    end = point(c, d);
    if (end < start) {
      point x = start;
      start = end;
      end = x;
    }
  }

  void draw() {
    fl_color(FL_BLACK);
    fl_line(start.x, HEIGHT - start.y, end.x, HEIGHT - end.y);
  }
};

int projection(point a, segment b) {
  if (a.x == b.start.x) {
    return b.start.y;
  } else if (a.x == b.end.x) {
    return b.end.y;
  } else {
    return b.start.y + ((b.end.y - b.start.y) * (a.x - b.start.x)) / (b.end.x - b.start.x);
  }
}

struct trapezoid {
  segment top, bottom;
  point left, right;
  trapezoid *up, *down, *next, *prev;

  trapezoid(segment a, segment b, point c, point d) {
    top = a;
    bottom = b;
    left = c;
    right = d;
  }

  void draw() {
    top.draw();
    bottom.draw();

    int left_high_end = HEIGHT;
    int left_low_end = 1;
    int right_high_end = HEIGHT;
    int right_low_end = 1;
    if (left.x >= top.start.x && left.x <= top.end.x) {
      left_high_end = projection(left, top);
    }
    if (left.x >= bottom.start.x && left.x <= bottom.end.x) {
      left_low_end = projection(left, bottom);
    }
    if (right.x >= top.start.x && right.x <= top.end.x) {
      right_high_end = projection(right, top);
    }
    if (right.x >= bottom.start.x && right.x <= bottom.end.x) {
      right_low_end = projection(right, bottom);
    }
    
    fl_color(FL_RED);
    segment(left.x, left_high_end, left.x, left_low_end).draw();
    segment(right.x, right_high_end, right.x, right_low_end).draw();
  }

  ~trapezoid() {}
};


struct TMap_Widget:Fl_Widget {
  vector <segment> segments;
  TMap_Widget(int x, int y, int w, int h, const char *label = 0) : Fl_Widget(x, y, w, h, label) {}

  void draw() {
    fl_draw_box	(FL_FLAT_BOX, 0, 0, WIDTH, HEIGHT, FL_WHITE);		
    for (int i = 0; i < (int)segments.size(); ++i) {
      segments[i].draw();
    }

    segment b(200, 200, 300, 300);
    segment a(100, 100, 400, 100);
    point c(250, 250);
    point d(300, 300);
    trapezoid t(b, a, c, d);
    t.draw();
  }
};

int main(int argc, char** argv) {
  int n, a, b, c, d;
  vector<segment> v;
  
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c >> d; 
    v.push_back(segment(a, b, c, d));
  }

  Fl_Window *window = new Fl_Window(WIDTH, HEIGHT);
  TMap_Widget *tmap = new TMap_Widget(0, 0, WIDTH, HEIGHT);
  tmap->segments = v;
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
