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
void trapezoid_node::set_left(std::shared_ptr<node>){
  return;
}
void trapezoid_node::set_right(std::shared_ptr<node>){
  return;
}
std::shared_ptr<node> trapezoid_node::get_left(){
  return nullptr;
}
std::shared_ptr<node> trapezoid_node::get_right(){
  return nullptr;
}
std::vector<std::shared_ptr<node>> trapezoid_node::get_previous(){
  return previous;
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
void trapezoid_node::set_previous(std::shared_ptr<node> pr) {
  previous.push_back(pr);
}
trapezoid* trapezoid_node::get_trapezoid() {
  return t;
}
