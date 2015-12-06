#include "search.h"

segment_node::segment_node(std::shared_ptr<segment> n){
  s = n;
}

int segment_node::get_direction(point p, segment segm) {
  int l = left_turn(s.get()->start, s.get()->end, p);
  if (l != 0)
    return 0;
  if (p == segm.start)
    return left_turn(s.get()->start, s.get()->end, segm.end);
  return left_turn(s.get()->start, s.get()->end, segm.start);
}
int segment_node::get_direction(point p ) {
  return left_turn(s.get()->start, s.get()->end, p);
}
void segment_node::set_left(std::shared_ptr<node> p) {
  up = p;
}
void segment_node::set_right(std::shared_ptr<node> p) {
  down = p;
}
std::shared_ptr<node> segment_node::get_left() {
  return up;
}
std::shared_ptr<node> segment_node::get_right() {
  return down;
}
std::vector<std::shared_ptr<node>> segment_node::get_previous() {
  return previous;
}
segment segment_node::get_segment() {
  return *s.get();
}
void segment_node::set_previous(std::shared_ptr<node> prev) {
  if (previous.size() == 0)
    previous.push_back(prev);
  else
    previous[0] = prev;
}
