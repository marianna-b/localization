#include "visualize.h"
#include <iostream>
#include <utility>
using namespace std;

trapezoid count_bounds(vector <segment> &v, double gap) {
  double max_x = 0, max_y = 0, min_x = 1400, min_y = 1400;

  for (int i = 0; i < (int)v.size(); ++i) {
    max_x = max(max_x, max(v[i].start.x, v[i].end.x));
    min_x = min(min_x, min(v[i].start.x, v[i].end.x));
    max_y = max(max_y, max(v[i].start.y, v[i].end.y));
    min_y = min(min_y, min(v[i].start.y, v[i].end.y));
  }

  if (v.size() == 0) {
    max_x = 1348;
    max_y = 748;
    min_x = 1;
    min_y = 1;
  } else {
    min_x -= gap;
    min_y -= gap;
    max_x += gap;
    max_y += gap;
  }

  // TODO free this shit
  segment* top = new segment(min_x, max_y, max_x, max_y);
  segment* bottom = new segment(min_x, min_y, max_x, min_y);
  return trapezoid(top, bottom, bottom->start, top->end);
}

// TODO make bounds allocate in construction of search struct
int main(int argc, char** argv) {
  vector <segment> v;
  double a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    v.emplace_back(a, b, c, d);
  }
  double gap = 30.0;
  trapezoid t = count_bounds(v, gap);
  return visualize(argc, argv, v, gap, t);
}
