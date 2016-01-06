#include "search.h"

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

void point_node::set_left(std::shared_ptr<node> a){
  left = a;
}

void point_node::set_right(std::shared_ptr<node> b){
  right = b;
}

std::shared_ptr<node> point_node::get_left(){
  return left;
}

std::shared_ptr<node> point_node::get_right(){
  return right;
}

std::vector<std::shared_ptr<node>> point_node::get_previous(){
  return previous; 
}

segment* point_node::get_segment(){
  return p.get_segment();
}

void point_node::set_previous(std::shared_ptr<node> prev){
  if (previous.size() == 0)
    previous.push_back(prev);
  else
    previous[0] = prev;
}
