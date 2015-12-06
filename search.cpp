#include "search.h"

segment search_struct::find(point p){
  std::shared_ptr<node> curr(root);
  int res;
  while ((res = curr.get()->get_direction(p)) != 0) {
    if (res < 0)
      curr = curr.get()->get_left();
    else
      curr = curr.get()->get_right();
  }
  return curr.get()->get_segment();
}
trapezoid search_struct::find(point p, segment s){
  std::shared_ptr<node> curr(root);
  int res;
  while ((res = curr.get()->get_direction(p, s)) != 0) {
    if (res < 0)
      curr = curr.get()->get_left();
    else
      curr = curr.get()->get_right();
  }
  
  std::shared_ptr<trapezoid_node> r = std::dynamic_pointer_cast<trapezoid_node>(curr);
  return r.get()->get_trapezoid();
}

