#ifndef SEARCH_H
#define SEARCH_H

#include "trapezoid.h"
#include <vector>
#include <memory>

struct node {
  virtual int get_direction(point) = 0;
  virtual int get_direction(point, segment*) = 0;
  virtual void set_left(std::shared_ptr<node>)  = 0;
  virtual void set_right(std::shared_ptr<node>) = 0;
  virtual std::shared_ptr<node> get_left() = 0;
  virtual std::shared_ptr<node> get_right() = 0;
  virtual std::vector<std::shared_ptr<node>> get_previous() = 0;
  virtual segment* get_segment() = 0;
  virtual void set_previous(std::shared_ptr<node>) = 0;
};

struct search_struct {
  search_struct(std::shared_ptr<trapezoid>);
  segment* find(point);
  trapezoid* find(point, segment*);
private:
  std::shared_ptr<node> root;
};

struct point_node : node {
  point_node(point);
  int get_direction(point) override;
  int get_direction(point, segment*) override;
  void set_left(std::shared_ptr<node>) override;
  void set_right(std::shared_ptr<node>) override;
  std::shared_ptr<node> get_left() override;
  std::shared_ptr<node> get_right() override;
  std::vector<std::shared_ptr<node>> get_previous() override;
  segment* get_segment() override;
  void set_previous(std::shared_ptr<node>) override;
private:
  point p;
  std::shared_ptr<node> left = 0;
  std::shared_ptr<node> right = 0;
  std::vector<std::shared_ptr<node>> previous;
};

struct segment_node : node {
  segment_node(segment*);
  int get_direction(point) override;
  int get_direction(point, segment*) override;
  void set_left(std::shared_ptr<node>) override;
  void set_right(std::shared_ptr<node>) override;
  std::shared_ptr<node> get_left() override;
  std::shared_ptr<node> get_right() override;
  std::vector<std::shared_ptr<node>> get_previous() override;
  segment* get_segment() override;
  void set_previous(std::shared_ptr<node>) override;
private:
  segment* s;
  std::shared_ptr<node> up = 0;
  std::shared_ptr<node> down = 0;
  std::vector<std::shared_ptr<node>> previous;
};

struct trapezoid_node : node {
  trapezoid_node(trapezoid*);
  int get_direction(point) override;
  int get_direction(point, segment*) override;
  void set_left(std::shared_ptr<node>) override;
  void set_right(std::shared_ptr<node>) override;
  std::shared_ptr<node> get_left() override;
  std::shared_ptr<node> get_right() override;
  std::vector<std::shared_ptr<node>> get_previous() override;
  segment* get_segment() override;
  void set_previous(std::shared_ptr<node>) override;
  trapezoid* get_trapezoid();
private:
  trapezoid* t;
  std::vector<std::shared_ptr<node>> previous;
};

#endif
