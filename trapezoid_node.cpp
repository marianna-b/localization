#include "search.h"

trapezoid_node::trapezoid_node(trapezoid* n){
  t = n;
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
segment* trapezoid_node::get_segment() {
  return t->top;
}
void trapezoid_node::set_previous(std::shared_ptr<node> pr) {
  previous.push_back(pr);
}
trapezoid* trapezoid_node::get_trapezoid() {
  return t;
}
