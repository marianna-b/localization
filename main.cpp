#include "visualize.h"
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
  vector <segment> v;
  double a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    v.push_back(segment(a, b, c, d));
  }
  return visualize(argc, argv, v, 30.0);
}
