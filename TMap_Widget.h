#ifndef TMAP_WIDGET
#define TMAP_WIDGET

#include <FL/Fl.h>
#include <FL/x.H> 
#include <vector>
#include "trapezoid_map.h"

struct TMap_Widget:Fl_Widget {
  TMap_Widget(int, int, int, int, const char *);
  void draw();
  int handle(int event);

  std::vector <segment> segments;
  trapezoid bounds;
  double scale;
  trapezoid_map* map;
  segment* prev;
};

#endif
