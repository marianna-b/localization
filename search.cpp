#include "search.h"
void node::set_left(std::shared_ptr<node> p) {
  left = p;
}
void node::set_right(std::shared_ptr<node> p) {
  right = p;
}
std::shared_ptr<node> node::get_left() {
  return left;
}
std::shared_ptr<node> node::get_right() {
  return right;
}
std::vector<node*> node::get_previous() {
  return previous;
}
void node::set_previous(node* prev) {
    previous.push_back(prev);
}
