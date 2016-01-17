#include "search.h"
#include <iostream>
using namespace std;

point_node::point_node(point n){
  p = n;
}

int point_node::get_direction(point a, segment* b) {
  return get_direction(a);
}

int point_node::get_direction(point a) {
  if (a < p)
    return 1;
  else
    return -1;
}

segment* point_node::get_segment(trapezoid){
  return p.get_segment();
}
