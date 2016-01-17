#include "search.h"
#include <iostream>
using namespace std;

segment_node::segment_node(segment* n){
  s = n;
}

int segment_node::get_direction(point p, segment* segm) {
  int l = left_turn(s->start, s->end, p);

  if (l != 0)
    return l;
  if (p == s->start)
    return left_turn(s->start, s->end, segm->end);
  return left_turn(s->start, s->end, segm->start);
}
int segment_node::get_direction(point p ) {
  return left_turn(s->start, s->end, p);
}

segment* segment_node::get_segment(trapezoid) {
  return s;
}
