#ifndef SEARCH_H
#define SEARCH_H

#include "trapezoid.h"
#include <vector>
#include <memory>

struct node {
  virtual int get_direction(point) = 0;
  virtual int get_direction(point, segment*) = 0;
  virtual segment* get_segment(trapezoid) = 0;
  void set_left(std::shared_ptr<node>);
  void set_right(std::shared_ptr<node>);
  std::shared_ptr<node> get_left();
  std::shared_ptr<node> get_right();
  std::vector<node*> get_previous();
  void set_previous(node*);
protected:
  std::shared_ptr<node> left = 0;
  std::shared_ptr<node> right = 0;
  std::vector<node*> previous;
};

struct point_node : node {
  point_node(point);
  int get_direction(point) override;
  int get_direction(point, segment*) override;
  segment* get_segment(trapezoid) override;
private:
  point p;
};

struct segment_node : node {
  segment_node(segment*);
  int get_direction(point) override;
  int get_direction(point, segment*) override;
  segment* get_segment(trapezoid) override;
private:
  segment* s;
};

struct trapezoid_node : node {
  trapezoid_node(segment*, segment*, point, point);
  int get_direction(point) override;
  int get_direction(point, segment*) override;
  segment* get_segment(trapezoid) override;
  trapezoid* get_trapezoid();
  ~trapezoid_node();
private:
  void add_segments();
  void single_trap(trapezoid* t, segment* s);

  trapezoid* t;
};

#endif
