#include <iostream>
#include <utility>
#include "trapezoid_map.h"
#include <random>
#include <algorithm>
#include <iterator>
using namespace std;

bool bounding_box(int a, int b, int c, int d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d);
}

bool do_intersect(segment& a, segment& b) {
  return bounding_box(a.start.x, a.end.x, b.start.x, b.end.x)
      && bounding_box(a.start.y, a.end.y, b.start.y, b.end.y)
      && (left_turn(a.start, a.end, b.start) * left_turn(a.start, a.end, b.end) <= 0)
      && (left_turn(b.start, b.end, a.start) * left_turn(b.start, b.end, a.end) <= 0);
}


int main(int argc, char** argv) {
  int n = 50;
  vector <segment> v;
  double lower_bound = 0;
  double upper_bound = 100;

  uniform_real_distribution<double> unif(lower_bound,upper_bound);
  default_random_engine re;
  re.seed(time(NULL));
  while (v.size() < n) {
    bool f = true;
    segment s(unif(re), unif(re), unif(re), unif(re));
    for (int j = 0; j < v.size(); ++j) {
      if (do_intersect(s, v[j]))
        f = false;
    }
    if (f) {
      v.emplace_back(move(s));
      cout << s.start.x << " " << s.start.y << " " << s.end.x << " " << s.end.y << endl;
    }
  }
  /*
  vector <segment> v;
  double a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    v.emplace_back(a, b, c, d);
  }

  random_device rd;
  mt19937 g(rd());
 
  shuffle(v.begin(), v.end(), g);
  
  */
  trapezoid_map map(move(v), 10.0);
  return map.visualize(argc, argv);
}
