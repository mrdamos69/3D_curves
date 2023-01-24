#ifndef CURVES_H
#define CURVES_H

#define PI 3.14159265358979323846;

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

class Curve {
 public:
  virtual std::pair<double, double> Point(double value) = 0;
  virtual std::pair<double, double> Derivative(double value) = 0;
};

#endif  // CURVES_H
