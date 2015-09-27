#include <iostream>
#include <cstdio>
#include "TMap_Widget.h"
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
using namespace std;

const int WIDTH = 1300;
const int HEIGHT = 750;

void segment::draw() {
  fl_color(FL_BLACK);
  fl_line(start.x, HEIGHT - start.y, end.x, HEIGHT - end.y);
}

void trapezoid::draw() {
  top.draw();
  bottom.draw();
  
  int left_high_end = HEIGHT;
  int left_low_end = 1;
  int right_high_end = HEIGHT;
  int right_low_end = 1;
  
  if (left.x >= top.start.x && left.x <= top.end.x) {
    left_high_end = left.projection(top);
  }
  if (left.x >= bottom.start.x && left.x <= bottom.end.x) {
    left_low_end = left.projection(bottom);
  }
  if (right.x >= top.start.x && right.x <= top.end.x) {
    right_high_end = right.projection(top);
  }
  if (right.x >= bottom.start.x && right.x <= bottom.end.x) {
    right_low_end = right.projection(bottom);
  }
  
  fl_color(FL_RED);
  segment(left.x, left_high_end, left.x, left_low_end).draw();
  segment(right.x, right_high_end, right.x, right_low_end).draw();
}

TMap_Widget::TMap_Widget(int x, int y, int w, int h, const char *label = 0) : Fl_Widget(x, y, w, h, label) {}

void TMap_Widget::draw() {
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

int visualize(int argc, char** argv, std::vector <segment> v, int gap) {
  Fl_Window *window = new Fl_Window(WIDTH, HEIGHT);
  TMap_Widget *tmap = new TMap_Widget(0, 0, WIDTH, HEIGHT);
  tmap->segments = v;
  window->end();
  window->show(argc, argv);
  return Fl::run();
}
