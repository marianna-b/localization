#ifndef TRAPEZOID_MAP_H
#define TRAPEZOID_MAP_H

#include "search.h"
#include <map>

struct trapezoid_map {
  trapezoid_map(int, char**, std::vector<segment>, double);
  segment* find(point);
  trapezoid* find(point, segment*);
  int visualize();
  ~trapezoid_map();
  void single_trap(trapezoid*, segment*);
  void add_segments();
 
  std::shared_ptr<node> root;
  std::vector<segment> segments;
  std::map<trapezoid*, std::shared_ptr<node> > link;
  trapezoid bound;
  double gap;
  int argc;
  char** argv;
};

#endif
