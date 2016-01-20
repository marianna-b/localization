#ifndef TRAPEZOID_MAP_H
#define TRAPEZOID_MAP_H

#include "search.h"
#include <map>

struct trapezoid_map {
  trapezoid_map(std::vector<segment>, double);
  segment* find(point);
  trapezoid* find(point, segment*);
  int visualize(int, char**);
  ~trapezoid_map();
  void single_trapezoid(trapezoid*, segment*);
  void add_segment(segment&);
  std::shared_ptr<node> create_trapezoid_node(segment*, segment*, point, point);
  void set_link(std::shared_ptr<node>, std::shared_ptr<node>, trapezoid*);

 
  std::shared_ptr<node> root;
  std::vector<segment> segments;
  std::map<trapezoid*, std::shared_ptr<node> > link;
  trapezoid bound;
  double gap;
};

#endif
