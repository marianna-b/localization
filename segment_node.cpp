#include "search.h"
#include <iostream>
using namespace std;

segment_node::segment_node(segment* n)
  : s(n) {}

int segment_node::get_direction(point p, segment* segm) {
  int l = left_turn(s->start, s->end, p);
  //cout << "l " << l << endl;
  //cout << p.x << " " << p.y << endl;
  //cout << s->start.x << " " << s->start.y << " " << s->end.x << " " << s->end.y << endl;
  if (l != 0)
    return l;
  //cout << "fu" << endl;
  //cout << segm->end.x << " " << segm->end.y << endl;
  if (p == s->start)
    return left_turn(s->start, s->end, segm->end);
  return left_turn(s->start, s->end, segm->start);
}
int segment_node::get_direction(point p ) {
  return left_turn(s->start, s->end, p);
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
segment* segment_node::get_segment(trapezoid) {
  return s;
}
void segment_node::set_previous(std::shared_ptr<node> prev) {
    previous.push_back(prev);
}
