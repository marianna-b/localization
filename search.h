#ifndef SEARCH_H
#define SEARCH_H

#include "trapezoid.h"
#include <vector>
#include <memory>

struct node {
  virtual int get_direction(point);
  virtual int get_direction(point, segment);
  virtual void set_left(std::shared_ptr<node>) ;
  virtual void set_right(std::shared_ptr<node>) ;
  virtual std::shared_ptr<node> get_left() ;
  virtual std::shared_ptr<node> get_right() ;
  virtual std::vector<std::shared_ptr<node>> get_previous() ;
  virtual segment get_segment() ;
  virtual void set_previous(std::shared_ptr<node>);
};

struct search_struct {
  search_struct(std::shared_ptr<trapezoid>);
  segment find(point);
  trapezoid find(point, segment);
private:
  std::shared_ptr<node> root;
};

struct point_node:node {
  point_node(std::shared_ptr<point>);
  int get_direction(point);
  int get_direction(point, segment);
  void set_left(std::shared_ptr<node>);
  void set_right(std::shared_ptr<node>);
  std::shared_ptr<node> get_left();
  std::shared_ptr<node> get_right();
  std::vector<std::shared_ptr<node>> get_previous();
  segment get_segment();
  void set_previous(std::shared_ptr<node>);
private:
  std::shared_ptr<point> p;
  std::shared_ptr<node> left = 0;
  std::shared_ptr<node> right = 0;
  std::vector<std::shared_ptr<node>> previous;
};

struct segment_node:node {
  segment_node(std::shared_ptr<segment>);
  int get_direction(point);
  int get_direction(point, segment);
  void set_left(std::shared_ptr<node>);
  void set_right(std::shared_ptr<node>);
  std::shared_ptr<node> get_left();
  std::shared_ptr<node> get_right();
  std::vector<std::shared_ptr<node>> get_previous();
  segment get_segment();
  void set_previous(std::shared_ptr<node>);
private:
  std::shared_ptr<segment> s;
  std::shared_ptr<node> up = 0;
  std::shared_ptr<node> down = 0;
  std::vector<std::shared_ptr<node>> previous;
};

struct trapezoid_node:node {
  trapezoid_node(std::shared_ptr<trapezoid>);
  int get_direction(point);
  int get_direction(point, segment);
  void set_left(std::shared_ptr<node>);
  void set_right(std::shared_ptr<node>);
  std::shared_ptr<node> get_left();
  std::shared_ptr<node> get_right();
  std::vector<std::shared_ptr<node>> get_previous();
  segment get_segment();
  void set_previous(std::shared_ptr<node>);
  trapezoid get_trapezoid();
private:
  std::shared_ptr<trapezoid> t;
  std::vector<std::shared_ptr<node>> previous;
};

#endif
