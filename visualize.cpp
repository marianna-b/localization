#include <iostream>
#include <cstdio>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

using namespace std;

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

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

int main(int argc, char** argv) {
  /*
  int n, a, b, c, d;
  vector<segment> v;
  cin >> n;
  for (auto i = 0; i < n; ++i) {
    cin >> a >> b >> c >> d; 
    v.push_back(segment(a, b, c, d));
  }
  */

  Fl_Window *window = new Fl_Window(340,180);
  Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD + FL_ITALIC);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
