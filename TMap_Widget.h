#ifndef TMAP_WIDGET
#define TMAP_WIDGET

#include <FL/Fl.h>
#include <FL/x.H> 
#include <vector>
#include "trapezoid.h"

struct TMap_Widget:Fl_Widget {
  TMap_Widget(int, int, int, int, const char *);
  void draw();

  std::vector <segment> segments;
};

#endif
