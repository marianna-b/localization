#include <iostream>
#include <cstdio>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/x.H> 

using namespace std;

struct point {
  int x, y;

  point() {
    x = y = 0;
  }

  point(int a, int b) {
    x = a;
    y = b;
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
  }
                         
};

const int WIDTH = 1300;
const int HEIGHT = 750;

struct TMap_Widget:Fl_Widget {
  vector <segment> segments;
  TMap_Widget(int x, int y, int w, int h, const char *label = 0) : Fl_Widget(x, y, w, h, label) {}

  void draw() {
    fl_draw_box	(FL_FLAT_BOX, 0, 0, WIDTH, HEIGHT, FL_WHITE);		
    fl_color(FL_BLACK);
    for (int i = 0; i < (int)segments.size(); ++i) {
      fl_line(segments[i].start.x, segments[i].start.y, segments[i].end.x, segments[i].end.y);
    }
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
