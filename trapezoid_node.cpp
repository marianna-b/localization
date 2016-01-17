#include "search.h"
#include <iostream>

using namespace std;

trapezoid_node::trapezoid_node(segment *a, segment *b, point c, point d) {
  t = new trapezoid(a, b, c, d);
}
trapezoid_node::~trapezoid_node(){
  delete(t);
}
int trapezoid_node::get_direction(point, segment*) {
  return 0;
}
int trapezoid_node::get_direction(point) {
  return 0;
}
segment* trapezoid_node::get_segment(trapezoid bound) {
  if (bound.top != t->top)
    return t->top;
  if (bound.bottom != t->bottom)
    return t->bottom;

  if (t->left == t->bottom->start)
    return t->right.get_segment();
  return t->left.get_segment();
}
trapezoid* trapezoid_node::get_trapezoid() {
  return t;
}
